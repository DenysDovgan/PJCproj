//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_WORD_H
#define PJCPROJ_WORD_H

#include <SFML/Graphics.hpp>

class Word : public sf::Drawable {
public:
    Word(const std::string& text, const sf::Font& font, float speed);
    auto update(sf::Time elapsedTime) -> void;
    auto isOffScreen() const -> bool;
    auto matchTyping(const std::string& typed) -> bool;

private:
    sf::Text wordText;
    float speed;
    std::string typedText;

    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};


#endif //PJCPROJ_WORD_H
