//
// Created by s30460 on 2024-05-28.
//

#include "../headers/Settings.h"
#include <fstream>


Settings::Settings() {
    sf::Font arial, times, calibri;
    arial.loadFromFile("../assets/fonts/arial.ttf");
    times.loadFromFile("../assets/fonts/timesNewRoman.ttf");
    calibri.loadFromFile("../assets/fonts/calibri.ttf");

    fonts.clear();

    fonts.insert(std::pair<std::string, sf::Font>("Arial", arial));
    fonts.insert(std::pair<std::string, sf::Font>("Calibri", calibri));
    fonts.insert(std::pair<std::string, sf::Font>("Times New Roman", times));

    currentFontName = "Arial";
    font = fonts[currentFontName];

}

auto Settings::getFont() -> sf::Font& {
    return font;
}
auto Settings::getFonts() -> std::map<std::string, sf::Font> {
    return fonts;
}

auto Settings::setFont(const sf::Font& newFont) -> void {
    font = newFont;
}

auto Settings::getIteratorByFontName(const std::string& name) -> std::map<std::string, sf::Font>::iterator {
    return fonts.find(name);
}

auto Settings::getFontByName(const std::string& name) -> sf::Font& {
    auto it = fonts.find(name);
    if (it != fonts.end()) {
        return it->second;
    }
    throw std::runtime_error("Font not found: " + name);
}
auto Settings::setCurrentFontName(const std::string& fontName) -> void {
    currentFontName = fontName;
}

auto Settings::getFontNames() const -> std::vector<std::string> {
    std::vector<std::string> names;
    for (const auto& pair : fonts) {
        names.push_back(pair.first);
    }
    return names;
}

auto Settings::getCurrentFontName() const -> std::string {
    return currentFontName;
}
