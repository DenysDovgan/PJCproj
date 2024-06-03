//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameScene.h"
#include "../headers/GameEngine.h"
#include "../headers/Word.h"
#include "../headers/GameOverScene.h"
#include <fstream>
#include <stdexcept>

GameScene::GameScene(GameEngine& engine, WordSpeed speed) : Scene(engine), wordSpeed(speed) {
    font.loadFromFile("../assets/fonts/arial.ttf");
    loadWordsFromFile("../assets/words/words.txt");
}

GameScene::~GameScene() {}

auto GameScene::onUpdate(sf::Time elapsedTime) -> void {

}

auto GameScene::handleEvent(const sf::Event& event) -> void {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
            handleTyping(std::string(1, static_cast<char>(event.text.unicode))); // Correctly pass string
        }
    }
}

auto GameScene::spawnWord() -> void {

}

auto GameScene::handleTyping(const std::string& typed) -> void {
    // Handle typing, remove words from the list if fully typed
}

auto GameScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    for (const auto& word : words) {
        target.draw(word, states);
    }
}

auto GameScene::loadWordsFromFile(const std::string& wordListLocation) -> void {

}

