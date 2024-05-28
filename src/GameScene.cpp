//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameScene.h"
#include "../headers/GameEngine.h"
#include "../headers/GameOverScene.h"

GameScene::GameScene(GameEngine& engine) : Scene(engine) {
    font.loadFromFile("assets/fonts/arial.ttf");
    // Initialize words, load initial words from file, etc.
}

GameScene::~GameScene() {}

void GameScene::onUpdate(sf::Time elapsedTime) {
    for (auto& word : words) {
        word.update(elapsedTime);
        if (word.isOffScreen()) {
            gameEngine.changeScene(std::make_unique<GameOverScene>(gameEngine));
            return;
        }
    }
    // Spawn new words periodically
    spawnWord();
}

void GameScene::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            handleTyping(static_cast<char>(event.text.unicode));
        }
    }
}

void GameScene::spawnWord() {
    // Add logic to spawn a new word at random intervals
}

void GameScene::handleTyping(const std::string& typed) {
    // Handle typing, remove words from the list if fully typed
}

void GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& word : words) {
        target.draw(word, states);
    }
}

