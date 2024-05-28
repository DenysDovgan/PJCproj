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

void Settings::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        json j;
        file >> j;
        wordSpeed = j["wordSpeed"];
        wordSize = j["wordSize"];
        font.loadFromFile(j["fontPath"]);
    }
}

void Settings::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        json j;
        j["wordSpeed"] = wordSpeed;
        j["wordSize"] = wordSize;
        j["fontPath"] = "assets/fonts/arial.ttf"; // Example font path
        file << j;
    }
}

sf::Font& Settings::getFont() {
    return font;
}

void Settings::setFont(const sf::Font& newFont) {
    font = newFont;
}

float Settings::getWordSpeed() const {
    return wordSpeed;
}

void Settings::setWordSpeed(float speed) {
    wordSpeed = speed;
}

unsigned int Settings::getWordSize() const {
    return wordSize;
}

void Settings::setWordSize(unsigned int size) {
    wordSize = size;
}
