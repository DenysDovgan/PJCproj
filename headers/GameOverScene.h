//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_GAMEOVERSCENE_H
#define PJCPROJ_GAMEOVERSCENE_H


#include "Scene.h"

class GameOverScene : public Scene {
public:
    GameOverScene(GameEngine& engine);
    virtual ~GameOverScene();

    void onUpdate(sf::Time elapsedTime) override;
    void handleEvent(const sf::Event& event) override;

private:
    sf::Text gameOverText;
    sf::Font font;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //PJCPROJ_GAMEOVERSCENE_H
