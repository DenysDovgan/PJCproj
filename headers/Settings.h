//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_SETTINGS_H
#define PJCPROJ_SETTINGS_H


#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>


enum class WordSpeed {
    SLOW = 50,
    MEDIUM = 100,
    FAST = 150,
    IMPOSABLE = 200
};

class Settings {
public:
    Settings();
    auto loadFromFile(const std::string& filename) -> void;
    auto saveToFile(const std::string& filename) const -> void;

    // Getters and setters for various settings
    sf::Font& getFont();
    auto setFont(const sf::Font& font) -> void;

    auto getWordSpeed() const -> float;
    auto setWordSpeed(float speed) -> void;

    auto getWordSize() const -> unsigned int;
    auto setWordSize(unsigned int size) -> void;

private:
    sf::Font font;
    float wordSpeed;
    unsigned int wordSize;
};


#endif //PJCPROJ_SETTINGS_H
