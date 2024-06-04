//
// Created by s30460 on 2024-05-28.
//


#include "../headers/TitleScene.h"
#include "../headers/GameEngine.h"
#include "../headers/GameScene.h"
#include "../headers/Button.h"

TitleScene::TitleScene(GameEngine& engine) : Scene(engine) {


    // Menu buttons background
    menuBackground.setSize(sf::Vector2f(400.f, 600.f));
    menuBackground.setPosition(80, 180);
    menuBackground.setFillColor(sf::Color(64,64,64, 190));

    // Background image
    backgroundTexture.loadFromFile("../assets/images/monkibg2.jpg");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setScale(1, 1);
    backgroundImage.setPosition(0, 0);

    // Game title
    font.loadFromFile("../assets/fonts/Danfo.ttf");

    titleText.setFont(font);
    titleText.setString("MONKI TYPER");
    titleText.setCharacterSize(52);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(110 , 200);

    // Button Font
    buttonFont.loadFromFile("../assets/fonts/arial.ttf");

    // NewGame button
    startGameButton.setFont(font);
    startGameButton.setCharacterSize(30);
    startGameButton.setString("New Game");
    //startGameButton.setShapeSize(sf::Vector2f(30,30));
    startGameButton.setPosition(sf::Vector2f(menuBackground.getPosition().x + 30,300));

    // Increase speed button
    increaseSpeedButton.setFont(buttonFont);
    increaseSpeedButton.setCharacterSize(24);
    increaseSpeedButton.setString("+");
    increaseSpeedButton.setShapeSize(sf::Vector2f(30,30));
    increaseSpeedButton.setPosition(sf::Vector2f(320,500));

    // Decrease speed button
    decreaseSpeedButton.setFont(buttonFont);
    decreaseSpeedButton.setCharacterSize(24);
    decreaseSpeedButton.setString("-");
    decreaseSpeedButton.setShapeSize(sf::Vector2f(30,30));
    decreaseSpeedButton.setPosition(sf::Vector2f(370,500));


    // Word speed text
    speedText.setFont(font);
    speedText.setCharacterSize(24);
    speedText.setFillColor(sf::Color::White);
    speedText.setPosition(100, 500);
    wordSpeed = WordSpeed::MEDIUM;
    updateTextSpeed();
}

TitleScene::~TitleScene() {}

auto TitleScene::onUpdate(sf::Time elapsedTime) -> void {};


auto TitleScene::handleEvent(const sf::Event& event) -> void {
    increaseSpeedButton.handleEvent(event, gameEngine.getWindow());
    decreaseSpeedButton.handleEvent(event, gameEngine.getWindow());
    startGameButton.handleEvent(event, gameEngine.getWindow());

    if (startGameButton.isClicked()) {
        gameEngine.changeScene(std::make_unique<GameScene>(gameEngine, wordSpeed, "../assets/wordlist.txt"));
    }
    if (decreaseSpeedButton.isClicked()) {
        wordSpeed = static_cast<WordSpeed>(std::max(static_cast<int>(wordSpeed) - 50, 50));
        updateTextSpeed();
    }
    if (increaseSpeedButton.isClicked()) {
        wordSpeed = static_cast<WordSpeed>(std::min(static_cast<int>(wordSpeed) + 50, 200));
        updateTextSpeed();
    }
}

auto TitleScene::updateTextSpeed() -> void {
    auto speedString = std::string();
    switch (wordSpeed) {
        case WordSpeed::SLOW: speedString = "Speed: Slow"; break;
        case WordSpeed::MEDIUM: speedString = "Speed: Medium"; break;
        case WordSpeed::FAST: speedString = "Speed: Fast"; break;
        case WordSpeed::IMPOSSIBLE: speedString = "Speed: Impossible"; break;
    }
    speedText.setString(speedString);
}

auto TitleScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    target.draw(backgroundImage, states);
    target.draw(menuBackground, states);

    target.draw(titleText, states);

    target.draw(startGameButton, states);
    target.draw(increaseSpeedButton, states);
    target.draw(decreaseSpeedButton, states);

    target.draw(startGameText, states);
    target.draw(speedText, states);
}
