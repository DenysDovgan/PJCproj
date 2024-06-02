//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameOverScene.h"
#include "../headers/GameEngine.h"
#include "../headers/TitleScene.h"

GameOverScene::GameOverScene(GameEngine& engine) : Scene(engine) {
    font.loadFromFile("../assets/fonts/arial.ttf");
    gameOverText.setFont(font);
    gameOverText.setString("Game Over\nPress Enter to Return to Title");
    gameOverText.setCharacterSize(24);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(100, 100);
}

GameOverScene::~GameOverScene() {}

auto GameOverScene::onUpdate(sf::Time elapsedTime) -> void {
    // Update logic here
}

auto GameOverScene::handleEvent(const sf::Event& event) -> void {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        gameEngine.changeScene(std::make_unique<TitleScene>(gameEngine));
    }
}

auto GameOverScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    target.draw(gameOverText, states);
}
