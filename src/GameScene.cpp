//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameScene.h"
#include "../headers/GameEngine.h"
#include "../headers/GameOverScene.h"
#include <random>
#include <fstream>
#include <utility>

GameScene::GameScene(GameEngine& engine, WordSpeed speed, std::string  fileLoc, const sf::Font& font)
                    : Scene(engine, settings), wordSpeed(speed), textFileLocation(std::move(fileLoc)), font(font) {

    possibleWordsOffScreenCount = 9;

    score = 0;

    enteredCharsDisplay.setFont(font);
    enteredCharsDisplay.setCharacterSize(24);
    enteredCharsDisplay.setPosition(sf::Vector2f(gameEngine.getWindow().getSize().x - 300, 10));

    enteredCharsDisplayTitle.setFont(font);
    enteredCharsDisplayTitle.setCharacterSize(24);
    enteredCharsDisplayTitle.setString("Typed word:");
    enteredCharsDisplayTitle.setPosition(
            sf::Vector2f(enteredCharsDisplay.getPosition().x - 145, enteredCharsDisplay.getPosition().y));

    livesLeftDisplay.setFont(font);
    livesLeftDisplay.setCharacterSize(24);
    livesLeftDisplay.setString(std::to_string(possibleWordsOffScreenCount));
    livesLeftDisplay.setPosition(sf::Vector2f(gameEngine.getWindow().getSize().x - 1620, 10));

    livesLeftDisplayTitle.setFont(font);
    livesLeftDisplayTitle.setCharacterSize(24);
    livesLeftDisplayTitle.setString("Lives left:");
    livesLeftDisplayTitle.setPosition(
            sf::Vector2f(livesLeftDisplay.getPosition().x - 145, livesLeftDisplay.getPosition().y));

    scoreDisplay.setFont(font);
    scoreDisplay.setCharacterSize(24);
    scoreDisplay.setString(std::to_string(score));
    scoreDisplay.setPosition(sf::Vector2f(gameEngine.getWindow().getSize().x - 1220, 10));

    scoreDisplayTitle.setFont(font);
    scoreDisplayTitle.setCharacterSize(24);
    scoreDisplayTitle.setString("Score:");
    scoreDisplayTitle.setPosition(
            sf::Vector2f(scoreDisplay.getPosition().x - 145, scoreDisplay.getPosition().y));

    gameSceneMenuBackground.setSize(sf::Vector2f(gameEngine.getWindow().getSize().x, 50.f));
    gameSceneMenuBackground.setPosition(sf::Vector2f(0, 0));
    gameSceneMenuBackground.setFillColor(sf::Color(64, 64, 64, 190));

}

GameScene::~GameScene() {}

auto GameScene::onUpdate(sf::Time elapsedTime) -> void {
    updateWordPositions(elapsedTime);
    checkEnteredWord();
    checkWordOffScreen();
}

auto GameScene::handleEvent(const sf::Event& event) -> void {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            char enteredChar = static_cast<char>(event.text.unicode);
            if (std::isprint(enteredChar)) {
                enteredChars.push_back(enteredChar);
            } else if (enteredChar == '\b' && !enteredChars.empty()) {
                enteredChars.pop_back();
            }
        }
    }
}

auto GameScene::loadRandomWordFromFile() -> void {
    std::ifstream file(textFileLocation);
    // - REWRITE !!!
    // Line randomisation was taken from https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    std::random_device seed;
    std::mt19937 prng(seed());
    std::string line, randomWord;
    for(std::size_t n = 0; std::getline(file, line); n++) {
        std::uniform_int_distribution<> dist(0, n);
        if (dist(prng) < 1)
            randomWord = line;
    }
    spawnWord(randomWord);
}


auto GameScene::spawnWord(const std::string& word) -> void {
    sf::Text newWord(word, font, 24);
    newWord.setPosition(sf::Vector2f(-newWord.getLocalBounds().width,
                                     static_cast<float>(rand() % (gameEngine.getWindow().getSize().y - 50) + 50  )));
    words.emplace_back(newWord);
}

auto GameScene::updateWordPositions(sf::Time elapsedTime) -> void {
    auto speedFactor = static_cast<float>(wordSpeed);
    lastWordSpawn += elapsedTime;

    for (auto &word : words) {
        word.move(speedFactor * elapsedTime.asSeconds(), 0);
    }

    sf::Time spawnDelay = sf::seconds(1.0f / (speedFactor / 50.0f));
    if (lastWordSpawn >= spawnDelay) {
        lastWordSpawn = sf::Time::Zero;

        loadRandomWordFromFile();
    }
}
auto GameScene::checkEnteredWord() -> void {
    std::string enteredWord(enteredChars.begin(), enteredChars.end());

    for (auto it = words.begin(); it != words.end();) {
        if (it->getString() == enteredWord) {
            it = words.erase(it);
            score += 10;
            scoreDisplay.setString(std::to_string(score));
            enteredChars.clear();
            break;
        } else {
            ++it;
        }
    }

    enteredCharsDisplay.setString(enteredWord);
}
auto GameScene::checkWordOffScreen() -> void {
    for (auto it = words.begin(); it != words.end();) {
        if (it->getPosition().x > gameEngine.getWindow().getSize().x) {
            it = words.erase(it);
            --possibleWordsOffScreenCount;
            livesLeftDisplay.setString(std::to_string(possibleWordsOffScreenCount));
        } else {
            ++it;
        }
    }
    if (possibleWordsOffScreenCount <=0) {
        gameEngine.changeScene(std::make_unique<GameOverScene>(gameEngine, score));
    }
}


auto GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    for (const auto& word : words) {
        target.draw(word, states);
        target.draw(gameSceneMenuBackground, states);

        target.draw(enteredCharsDisplayTitle, states);
        target.draw(enteredCharsDisplay, states);

        target.draw(livesLeftDisplay, states);
        target.draw(livesLeftDisplayTitle, states);

        target.draw(scoreDisplay, states);
        target.draw(scoreDisplayTitle, states);
    }
}



