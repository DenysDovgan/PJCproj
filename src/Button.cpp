//
// Created by 12qwa on 6/2/2024.
//

#include "../headers/Button.h"

Button::Button() : clicked(false) {
    buttonShape.setSize(sf::Vector2f(buttonText.getLocalBounds().width + 20, buttonText.getLocalBounds().height + 20));
    buttonShape.setFillColor(sf::Color::Blue);

    buttonText.setCharacterSize(60);
    buttonText.setFillColor(sf::Color::White);



}

auto Button::handleEvent(const sf::Event &event, const sf::RenderWindow &window) -> void {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (buttonShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            clicked = true;
        }
    } else {
        clicked = false;
    }
}
auto Button::isClicked() const -> bool {
    return clicked;
}

auto Button::draw(sf::RenderTarget &target, sf::RenderStates states) const -> void {
    target.draw(buttonShape, states);
    target.draw(buttonText, states);
}