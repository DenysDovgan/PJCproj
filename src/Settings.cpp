//
// Created by s30460 on 2024-05-28.
//

#include "../headers/Settings.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Settings::Settings() {
    font.loadFromFile("assets/fonts/arial.ttf");
}

auto Settings::loadFromFile(const std::string& filename) -> void {

}

auto Settings::saveToFile(const std::string& filename) const -> void {

}

auto Settings::getFont() -> sf::Font&{
    return font;
}

auto Settings::setFont(const sf::Font& newFont) -> void {

}
