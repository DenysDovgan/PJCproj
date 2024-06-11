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

    fonts = {arial, times, calibri};
    fontsName = {"Arial", "Times New Roman", "Calibri"};

    currentFontName = fontsName.at(0);
    font = fonts.at(0);

}

auto Settings::getFont() -> sf::Font& {
    return font;
}
auto Settings::getFonts() -> std::vector<sf::Font> {
    return fonts;
}

auto Settings::setFont(const sf::Font& newFont) -> void {
    font = newFont;
}

auto Settings::getPlaceInVectorByFontName(const std::string& name) -> int {
    for (int i = 0; i < fontsName.size(); ++i ) {
        if (name == fontsName.at(i))
            return i;
    }
    return 0;
}

auto Settings::getFontByName(const std::string& name) -> sf::Font& {
    for (int i = 0; i < fontsName.size(); ++i ) {
        if (name == fontsName.at(i))
            return fonts.at(i);
    }
    return fonts.at(0);
}
auto Settings::setCurrentFontName(const std::string& fontName) -> void {
    currentFontName = fontName;
}

auto Settings::getFontNames() const -> std::vector<std::string> {
    return fontsName;
}


auto Settings::getCurrentFontName() const -> std::string {
    return currentFontName;
}
