//
// Created by s30460 on 2024-05-28.
//

#include "../headers/Settings.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Settings::Settings() : wordSpeed(100.0f), wordSize(24) {
    font.loadFromFile("assets/fonts/arial.ttf");
}

auto Settings::loadFromFile(const std::string& filename) -> void {
    std::ifstream file(filename);
    if (file.is_open()) {
        json j;
        file >> j;
        wordSpeed = j["wordSpeed"];
        wordSize = j["wordSize"];
        font.loadFromFile(j["fontPath"]);
    }
}

auto Settings::saveToFile(const std::string& filename) const -> void {
    std::ofstream file(filename);
    if (file.is_open()) {
        json j;
        j["wordSpeed"] = wordSpeed;
        j["wordSize"] = wordSize;
        j["fontPath"] = "assets/fonts/arial.ttf"; // Example font path
        file << j;
    }
}

auto Settings::getFont() -> sf::Font&{
    return font;
}

auto Settings::setFont(const sf::Font& newFont) -> void {
    font = newFont;
}

auto Settings::getWordSpeed() const -> float {
    return wordSpeed;
}

auto Settings::setWordSpeed(float speed) -> void {
    wordSpeed = speed;
}

auto Settings::getWordSize() const -> unsigned int {
    return wordSize;
}

auto Settings::setWordSize(unsigned int size) -> void {
    wordSize = size;
}
