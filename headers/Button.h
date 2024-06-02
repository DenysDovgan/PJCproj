//
// Created by 12qwa on 6/2/2024.
//

#ifndef PJCPROJ_BUTTON_H
#define PJCPROJ_BUTTON_H

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
public:
    Button();

    auto handleEvent(const sf::Event& event, const sf::RenderWindow& window) -> void;
    auto isClicked() const -> bool;

    auto setString(const std::string& string) -> void {
        buttonText.setString(string);
    }
    auto setFont(sf::Font& font) -> void {
        buttonText.setFont(font);
    }
    auto setPosition(sf::Vector2f pos) -> void {
        buttonShape.setPosition(pos);
        buttonText.setPosition(pos /*- sf::Vector2f(10,10)*/ );
    }


private:
    sf::Text buttonText;
    sf::RectangleShape buttonShape;
    bool clicked;

    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};


#endif //PJCPROJ_BUTTON_H
