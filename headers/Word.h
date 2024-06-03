//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_WORD_H
#define PJCPROJ_WORD_H

#include <SFML/Graphics.hpp>
#include "Settings.h"

class Word : public sf::Drawable {
public:
    Word(const std::string& text, const sf::Font& font, WordSpeed speed, sf::Vector2f wordPos);

    auto updatePosition() -> void;
    auto isOffScreen() const -> bool;

private:
    sf::Vector2f wordPosition;

    sf::Text wordText;
    WordSpeed speed;

    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};


#endif //PJCPROJ_WORD_H
