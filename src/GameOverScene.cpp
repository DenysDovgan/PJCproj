//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameOverScene.h"
#include "../headers/GameEngine.h"
#include "../headers/TitleScene.h"

GameOverScene::GameOverScene(GameEngine &engine) : Scene(engine) {
    font.loadFromFile("../assets/fonts/font.ttf");
    gameOverText.setFont(font);
    gameOverText.setString("Game Over\nPress Enter to return to Title");
    gameOverText.setCharacterSize(24);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(100,100);
}

GameOverScene::~GameOverScene() {}

void GameOverScene::onUpdate(sf::Time elapsedTime) {
    // update logic here
}

void GameOverScene::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        gameEngine.changeScene(std::make_unique<TitleScene>(gameEngine));
    }
}

void::GameOverScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(gameOverText, states);
}
