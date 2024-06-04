//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameScene.h"
#include "../headers/GameEngine.h"
#include "../headers/GameOverScene.h"
#include <random>
#include <fstream>

GameScene::GameScene(GameEngine& engine, WordSpeed speed, const std::string& fileLoc)
                    : Scene(engine), wordSpeed(speed), textFileLocation(fileLoc) {
    font.loadFromFile("../assets/fonts/arial.ttf");

    enteredCharsBackground.setSize(sf::Vector2f(100.f, 40.f));
    enteredCharsBackground.setPosition(sf::Vector2f(enteredCharsDisplay.getPosition().x, 40) );
    enteredCharsBackground.setFillColor(sf::Color(64,64,64, 190));

    enteredCharsDisplayTitle.setFont(font);
    enteredCharsDisplayTitle.setCharacterSize(24);
    enteredCharsDisplayTitle.setString("Typed word:");
    enteredCharsDisplayTitle.setPosition(sf::Vector2f(enteredCharsDisplay.getPosition().x, 50));

    enteredCharsDisplay.setFont(font);
    enteredCharsDisplay.setCharacterSize(24);
    enteredCharsDisplay.setPosition(sf::Vector2f(gameEngine.getWindow().getSize().x - 200, 50));
}

GameScene::~GameScene() {}

auto GameScene::onUpdate(sf::Time elapsedTime) -> void {
    updateWordPositions(elapsedTime);
    checkEnteredWord();
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
                                     static_cast<float>(rand() % gameEngine.getWindow().getSize().y)));
    words.emplace_back(newWord);
}

auto GameScene::updateWordPositions(sf::Time elapsedTime) -> void {
    auto speedFactor = static_cast<float>(wordSpeed);
    lastWordSpawn += elapsedTime;

    for (auto it = words.begin(); it != words.end();) {
        it->move(speedFactor * elapsedTime.asSeconds(), 0);
        if (it->getPosition().x > gameEngine.getWindow().getSize().x) {
            it = words.erase(it); // Remove word if it goes off-screen
        } else {
            ++it;
        }
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
            enteredChars.clear();
            break;
        } else {
            ++it;
        }
    }

    enteredCharsDisplay.setString(enteredWord);
}

auto GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    for (const auto& word : words) {
        target.draw(word, states);
        target.draw(enteredCharsBackground, states);
        target.draw(enteredCharsDisplayTitle, states);
        target.draw(enteredCharsDisplay, states);
    }
}



