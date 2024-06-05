//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_GAMEOVERSCENE_H
#define PJCPROJ_GAMEOVERSCENE_H


#include "Scene.h"
#include "Button.h"

class GameOverScene : public Scene {
public:
    GameOverScene(GameEngine& engine);
    virtual ~GameOverScene();

    auto onUpdate(sf::Time elapsedTime) -> void override;
    auto handleEvent(const sf::Event& event) -> void override;

private:
    sf::Font font;
    sf::Font buttonFont;

    sf::Texture gameOverBackgroundTexture;
    sf::Sprite gameOverBackgroundImage;

    Button returnToTitleButton;
    Button exitGameButton;

    sf::Text gameOverText;

    sf::RectangleShape gameOverMenuBackground;

    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};


#endif //PJCPROJ_GAMEOVERSCENE_H
