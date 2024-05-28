//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_SETTINGS_H
#define PJCPROJ_SETTINGS_H


#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class Settings {
public:
    Settings();
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

    // Getters and setters for various settings
    sf::Font& getFont();
    void setFont(const sf::Font& font);

    float getWordSpeed() const;
    void setWordSpeed(float speed);

    unsigned int getWordSize() const;
    void setWordSize(unsigned int size);

private:
    sf::Font font;
    float wordSpeed;
    unsigned int wordSize;
};


#endif //PJCPROJ_SETTINGS_H
