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
    font.loadFromFile("../assets/fonts/arial.ttf");

    titleText.setFont(font);
    titleText.setString("MONKI TYPER");
    titleText.setCharacterSize(52);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(110 , 200);

    // Start Game Text
    startGameText.setFont(font);
    startGameText.setString("Press Enter to start the game");
    startGameText.setCharacterSize(42);
    startGameText.setFillColor(sf::Color::White);
    startGameText.setPosition(600 , 400);

    increaseSpeedButton.setString("+");
    increaseSpeedButton.setPosition(sf::Vector2f(400,500));
    increaseSpeedButton.setFont(font);

    // Word speed option
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
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            gameEngine.changeScene(std::make_unique<GameScene>(gameEngine, wordSpeed));
        } else if (event.key.code == sf::Keyboard::Down) {
            wordSpeed = static_cast<WordSpeed>(std::max(static_cast<int>(wordSpeed) - 50, 50));
            updateTextSpeed();
        } else if (event.key.code == sf::Keyboard::Up) {
            wordSpeed = static_cast<WordSpeed>(std::min(static_cast<int>(wordSpeed) + 50, 200));
            updateTextSpeed();
        }
    }
}

auto TitleScene::updateTextSpeed() -> void {
    auto speedString = std::string();
    switch (wordSpeed) {
        case WordSpeed::SLOW: speedString = "Speed: Slow"; break;
        case WordSpeed::MEDIUM: speedString = "Speed: Medium"; break;
        case WordSpeed::FAST: speedString = "Speed: Fast"; break;
        case WordSpeed::IMPOSABLE: speedString = "Speed: Very Fast"; break;
    }
    speedText.setString(speedString);
}

auto TitleScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    target.draw(backgroundImage, states);
    target.draw(menuBackground, states);
    target.draw(increaseSpeedButton, states);
    target.draw(titleText, states);
    target.draw(startGameText, states);
    target.draw(speedText, states);
}
