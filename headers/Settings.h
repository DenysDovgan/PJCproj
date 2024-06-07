//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_SETTINGS_H
#define PJCPROJ_SETTINGS_H


#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iterator>
#include <unordered_map>


enum class WordSpeed {
    SLOW = 50,
    MEDIUM = 100,
    FAST = 150,
    IMPOSSIBLE = 200
};


class Settings {
public:
    Settings();
    //auto loadFromFile(const std::string& filename) -> void;
    //auto saveToFile(const std::string& filename) const -> void;

    // Getters and setters for various settings
    sf::Font& getFont();
    auto setFont(const sf::Font& font) -> void;

    auto getIteratorByFontName(const std::string& name) -> std::map<std::string, sf::Font>::iterator;
    auto getFonts() -> std::map<std::string, sf::Font>;
    auto getFontByName(const std::string& name) -> sf::Font&;
    auto getFontNames() const -> std::vector<std::string>;
    auto getCurrentFontName() const -> std::string;
    auto setCurrentFontName(const std::string& fontName) -> void;


private:
    std::map<std::string, sf::Font> fonts;
    sf::Font font;
    std::string currentFontName;
};


#endif //PJCPROJ_SETTINGS_H
