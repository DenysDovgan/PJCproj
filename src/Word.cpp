//
// Created by s30460 on 2024-05-28.
//

#include "../headers/Word.h"

Word::Word(const std::string& text, const sf::Font& font, float speed) : speed(speed) {
    wordText.setFont(font);
    wordText.setString(text);
    wordText.setCharacterSize(24);
    wordText.setFillColor(sf::Color::White);
    wordText.setPosition(800, rand() % 600); // Random starting position
}

void Word::update(sf::Time elapsedTime) {
    wordText.move(-speed * elapsedTime.asSeconds(), 0);
}

bool Word::isOffScreen() const {
    return wordText.getPosition().x + wordText.getGlobalBounds().width < 0;
}

bool Word::matchTyping(const std::string& typed) {
    if (wordText.getString().substring(0, typed.size()) == typed) {
        typedText = typed;
        return typed.size() == wordText.getString().getSize();
    }
    return false;
}

void Word::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Text typedHighlight = wordText;
    typedHighlight.setString(typedText);
    typedHighlight.setFillColor(sf::Color::Green);
    target.draw(typedHighlight, states);
    target.draw(wordText, states);
}
