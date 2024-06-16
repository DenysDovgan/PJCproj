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
enum class WordSize {
    SMALL = 12,
    MEDIUM = 24,
    BIG = 36
};


class Settings {
public:
    Settings();

    auto setFont(const sf::Font& font) -> void;

    auto getPlaceInVectorByFontName(const std::string& name) -> int;
    auto getFonts() -> std::vector<sf::Font>;
    auto getFont() -> sf::Font&;
    auto getFontByName(const std::string& name) -> sf::Font&;
    auto getFontNames() const -> std::vector<std::string>;
    auto getCurrentFontName() const -> std::string;
    auto setCurrentFontName(const std::string& fontName) -> void;


private:
    std::vector<sf::Font> fonts;
    std::vector<std::string> fontsName;
    sf::Font font;
    std::string currentFontName;
};


#endif //PJCPROJ_SETTINGS_H
