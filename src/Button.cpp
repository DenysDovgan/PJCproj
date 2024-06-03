//
// Created by 12qwa on 6/2/2024.
//

#include "../headers/Button.h"

Button::Button() : clicked(false) {
    buttonText.setCharacterSize(60);
    buttonText.setFillColor(sf::Color::Black);

    buttonShape.setFillColor(sf::Color::White);
}
auto Button::setFont(sf::Font &font) -> void {
    buttonText.setFont(font);
}
auto Button::setCharacterSize(const int &characterSize) -> void {
    buttonText.setCharacterSize(characterSize);
}
auto Button::setPosition(sf::Vector2f pos) -> void {
    buttonShape.setPosition(pos);
    buttonText.setPosition(buttonShape.getPosition().x + buttonShape.getSize().x / 2.0f,
                           buttonShape.getPosition().y + buttonShape.getSize().y / 2.0f);
}
auto Button::setString(const std::string &str) -> void {
    buttonText.setString(str);
    buttonShape.setSize(sf::Vector2f(buttonText.getLocalBounds().width + 20, buttonText.getLocalBounds().height + 20));
    buttonText.setOrigin(buttonText.getLocalBounds().left + buttonText.getLocalBounds().width / 2.0f,
                         buttonText.getLocalBounds().top + buttonText.getLocalBounds().height / 2.0f);
    buttonText.setPosition(buttonShape.getPosition().x + buttonShape.getSize().x / 2.0f,
                           buttonShape.getPosition().y + buttonShape.getSize().y / 2.0f);
}
auto Button::setShapeSize(sf::Vector2f size) -> void {
    buttonShape.setSize(size);
    buttonText.setOrigin(buttonText.getLocalBounds().left + buttonText.getLocalBounds().width / 2.0f,
                         buttonText.getLocalBounds().top + buttonText.getLocalBounds().height / 2.0f);
    buttonText.setPosition(buttonShape.getPosition().x + buttonShape.getSize().x / 2.0f,
                           buttonShape.getPosition().y + buttonShape.getSize().y / 2.0f);
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