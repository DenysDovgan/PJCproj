//
// Created by s30460 on 2024-05-28.
//


#include "../headers/TitleScene.h"
#include "../headers/GameEngine.h"
#include "../headers/GameScene.h"

TitleScene::TitleScene(GameEngine& engine) : Scene(engine) {
    font.loadFromFile("../assets/fonts/arial.ttf");
    titleText.setFont(font);
    titleText.setString("Monki Typer");
    titleText.setCharacterSize(42);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(600 , 300);

    startGameText.setFont(font);
    startGameText.setString("Press Enter to start the game");
    startGameText.setCharacterSize(42);
    startGameText.setFillColor(sf::Color::White);
    startGameText.setPosition(600 , 400);

    texture.loadFromFile("../assets/images/monki.jpg");
    monkeyImage.setTexture(texture);
    monkeyImage.setScale(0.5, 0.5);
    monkeyImage.setPosition(300, 200);

    /*speedText.setFont(font);
    speedText.setCharacterSize(24);
    speedText.setFillColor(sf::Color::White);
    speedText.setPosition(100, 200);
    updateTextSpeed();*/
}

TitleScene::~TitleScene() {}

auto TitleScene::onUpdate(sf::Time elapsedTime) -> void {
    // Update logic here
}

auto TitleScene::handleEvent(const sf::Event& event) -> void {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        gameEngine.changeScene(std::make_unique<GameScene>(gameEngine));
    }
}

auto TitleScene::updateTextSpeed() -> void {
    std::string speedString;
    switch (selectedSpeed) {
        case WordSpeed::SLOW: speedString = "Speed: Slow"; break;
        case WordSpeed::MEDIUM: speedString = "Speed: Medium"; break;
        case WordSpeed::FAST: speedString = "Speed: Fast"; break;
        case WordSpeed::IMPOSABLE: speedString = "Speed: Very Fast"; break;
    }
    speedText.setString(speedString);
}

auto TitleScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    target.draw(titleText, states);
    target.draw(startGameText, states);
    target.draw(monkeyImage, states);
}
