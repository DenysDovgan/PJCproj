//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_TITLESCENE_H
#define PJCPROJ_TITLESCENE_H


#include "Scene.h"
#include "Settings.h"

class TitleScene : public Scene {
public:
    TitleScene(GameEngine& engine);
    virtual ~TitleScene();

    auto onUpdate(sf::Time elapsedTime) -> void override;
    auto handleEvent(const sf::Event& event) -> void override;

private:
    sf::Text titleText;
    sf::Text startGameText;
    sf::Font font;

    sf::Texture texture;
    sf::Sprite monkeyImage;

    sf::Text speedText;
    WordSpeed selectedSpeed;


    auto updateTextSpeed() -> void;
    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};


#endif //PJCPROJ_TITLESCENE_H
