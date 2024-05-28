//
// Created by s30460 on 2024-05-28.
//


#include "../headers/TitleScene.h"
#include "../headers/GameEngine.h"
#include "../headers/GameScene.h"

TitleScene::TitleScene(GameEngine& engine) : Scene(engine) {
    font.loadFromFile("../assets/fonts/arial.ttf");
    titleText.setFont(font);
    titleText.setString("Typing Game\nPress Enter to Start");
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(100, 100);
}

TitleScene::~TitleScene() {}

void TitleScene::onUpdate(sf::Time elapsedTime) {
    // Update logic here
}

void TitleScene::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        gameEngine.changeScene(std::make_unique<GameScene>(gameEngine));
    }
}

void TitleScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(titleText, states);
}
