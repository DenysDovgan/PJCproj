//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameEngine.h"
#include "../headers/TitleScene.h"


GameEngine::GameEngine() : window(sf::VideoMode(1920, 1080), "Typing Game") {
    settings.loadFromFile("assets/settings.json"); // Example settings file
    pushScene(std::make_unique<TitleScene>(*this));
}

GameEngine::~GameEngine() {}

auto GameEngine::run() -> void {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        auto elapsedTime = clock.restart();
        update(elapsedTime);
        render();
    }
}

auto GameEngine::changeScene(std::unique_ptr<Scene> scene) -> void {
    while (!scenes.empty()) popScene();
    pushScene(std::move(scene));
}

auto GameEngine::pushScene(std::unique_ptr<Scene> scene) -> void {
    scenes.push(std::move(scene));
}

auto GameEngine::popScene() -> void {
    scenes.pop();
}

auto GameEngine::processEvents() -> void {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        scenes.top()->handleEvent(event);
    }
}

auto GameEngine::update(sf::Time elapsedTime) -> void {
    scenes.top()->onUpdate(elapsedTime);
}

auto GameEngine::render() -> void {
    window.clear();
    window.draw(*scenes.top());
    window.display();
}

auto GameEngine::getSettings() -> Settings& {
    return settings;
}

