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

    virtual void onUpdate(sf::Time elapsedTime) = 0;
    virtual void handleEvent(const sf::Event& event) = 0;

protected:
    GameEngine& gameEngine;
};


#endif //PJCPROJ_SCENE_H
