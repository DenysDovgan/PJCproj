//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_GAMEENGINE_H
#define PJCPROJ_GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>
#include "Scene.h"
#include "Settings.h"

class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    auto run() -> void;

    auto changeScene(std::unique_ptr<Scene> scene) -> void;
    auto pushScene(std::unique_ptr<Scene> scene) -> void;
    auto popScene() -> void;

    auto getSettings() -> Settings&;

    auto getWindow() -> sf::RenderWindow&;
private:
    sf::RenderWindow window;
    std::stack<std::unique_ptr<Scene>> scenes;
    Settings settings;

    auto processEvents() -> void;
    auto update(sf::Time elapsedTime) -> void;
    auto render() -> void;
};


#endif //PJCPROJ_GAMEENGINE_H
