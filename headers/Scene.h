//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_SCENE_H
#define PJCPROJ_SCENE_H


#include <SFML/Graphics.hpp>

class GameEngine;

class Scene : public sf::Drawable {
public:
    Scene(GameEngine& engine);
    virtual ~Scene();

    virtual auto onUpdate(sf::Time elapsedTime) -> void = 0;
    virtual auto handleEvent(const sf::Event& event) -> void = 0;

protected:
    GameEngine& gameEngine;
};


#endif //PJCPROJ_SCENE_H
