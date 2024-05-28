//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameEngine.h"
#include "../headers/TitleScene.h"


GameEngine::GameEngine() : window(sf::VideoMode(800, 600), "Typing Game") {
    settings.loadFromFile("assets/settings.json"); // Example settings file
    pushScene(std::make_unique<TitleScene>(*this));
}

GameEngine::~GameEngine() {}

void GameEngine::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        sf::Time elapsedTime = clock.restart();
        update(elapsedTime);
        render();
    }
}

void GameEngine::changeScene(std::unique_ptr<Scene> scene) {
    while (!scenes.empty()) popScene();
    pushScene(std::move(scene));
}

void GameEngine::pushScene(std::unique_ptr<Scene> scene) {
    scenes.push(std::move(scene));
}

void GameEngine::popScene() {
    scenes.pop();
}

void GameEngine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        scenes.top()->handleEvent(event);
    }
}

void GameEngine::update(sf::Time elapsedTime) {
    scenes.top()->onUpdate(elapsedTime);
}

void GameEngine::render() {
    window.clear();
    window.draw(*scenes.top());
    window.display();
}

Settings& GameEngine::getSettings() {
    return settings;
}

