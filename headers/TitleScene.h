//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_TITLESCENE_H
#define PJCPROJ_TITLESCENE_H


#include "Scene.h"
#include "Settings.h"
#include "Button.h"

class TitleScene : public Scene {
public:
    TitleScene(GameEngine& engine, Settings& settings);
    virtual ~TitleScene();

    auto onUpdate(sf::Time elapsedTime) -> void override;
    auto handleEvent(const sf::Event& event) -> void override;

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundImage;

    Button startGameButton;

    sf::Text titleText;
    sf::Text startGameText;

    sf::Font font;
    sf::Font buttonFont;


    sf::RectangleShape menuBackground;

    // Word speed
    Button increaseSpeedButton;
    Button decreaseSpeedButton;

    sf::Text wordSpeedText;
    WordSpeed wordSpeed;

    // Word size
    Button nextWordSizeButton;
    Button prevWordSizeButton;

    sf::Text wordSizeText;
    WordSize wordSize;

    // Word font
    sf::Text wordFontText;

    Button nextFontButton;
    Button prevFontButton;


    auto updateTextSpeed() -> void;
    auto updateTextSize() -> void;
    auto updateTextFont() -> void;

    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};


#endif //PJCPROJ_TITLESCENE_H
