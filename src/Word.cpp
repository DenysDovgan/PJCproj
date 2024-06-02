//
// Created by s30460 on 2024-05-28.
//

#include "../headers/Word.h"

Word::Word(const std::string& text, const sf::Font& font, WordSpeed wordSpeed) {
    wordText.setFont(font);
    wordText.setString(text);
    wordText.setCharacterSize(24);
    wordText.setFillColor(sf::Color::White);
    wordText.setPosition(800, rand() % 600); // Random starting position

    speed = sf::Vector2f(-static_cast<float>(wordSpeed), 0.f);
}

auto Word::update(sf::Time elapsedTime) -> void {
    wordText.move(speed * elapsedTime.asSeconds());
}

auto Word::isOffScreen() const -> bool {
    return wordText.getPosition().x + wordText.getGlobalBounds().width < 0;
}

auto Word::matchTyping(const std::string& typed) -> bool {
    if (wordText.getString().substring(0, typed.size()) == typed) {
        typedText = typed;
        return typed.size() == wordText.getString().getSize();
    }
    return false;
}

auto Word::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    sf::Text typedHighlight = wordText;
    typedHighlight.setString(typedText);
    typedHighlight.setFillColor(sf::Color::Green);
    target.draw(typedHighlight, states);
    target.draw(wordText, states);
}

