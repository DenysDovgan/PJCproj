//
// Created by s30460 on 2024-05-28.
//

#include "../headers/Word.h"

Word::Word(const std::string& text, const sf::Font& font, WordSpeed wordSpeed, sf::Vector2f pos) : speed(wordSpeed) {
    wordText.setFont(font);
    wordText.setString(text);
    wordText.setCharacterSize(24);
    wordText.setFillColor(sf::Color::White);
    wordText.setPosition(pos);
}

auto Word::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    target.draw(wordText, states);
}

