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

    auto setCharacterSize(const int& characterSize) -> void;
    auto setFont(sf::Font& font) -> void;
    auto setPosition(sf::Vector2f pos) -> void;
    auto setShapeSize(sf::Vector2f size) -> void;
    auto setString(const std::string& str) -> void;


private:
    sf::Text buttonText;
    sf::RectangleShape buttonShape;
    bool clicked;

    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;
};


#endif //PJCPROJ_BUTTON_H
