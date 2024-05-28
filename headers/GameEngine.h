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

    void run();

    void changeScene(std::unique_ptr<Scene> scene);
    void pushScene(std::unique_ptr<Scene> scene);
    void popScene();

    Settings& getSettings();

private:
    sf::RenderWindow window;
    std::stack<std::unique_ptr<Scene>> scenes;
    Settings settings;

    void processEvents();
    void update(sf::Time elapsedTime);
    void render();
};


#endif //PJCPROJ_GAMEENGINE_H
