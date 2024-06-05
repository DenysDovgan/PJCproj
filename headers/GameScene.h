//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_GAMESCENE_H
#define PJCPROJ_GAMESCENE_H


#include <vector>
#include "Scene.h"
#include "Settings.h"

class GameScene : public Scene {
public:
    GameScene(GameEngine& engine, WordSpeed speed, const std::string& fileLoc);
    virtual ~GameScene();

    auto onUpdate(sf::Time elapsedTime) -> void override;
    auto handleEvent(const sf::Event& event) -> void override;

private:
    std::string textFileLocation;
    sf::Font font;
    WordSpeed wordSpeed;
    sf::Time lastWordSpawn;
    std::vector<sf::Text> words;

    std::vector<char> enteredChars;

    sf::RectangleShape gameSceneMenuBackground;
    sf::Text enteredCharsDisplay;
    sf::Text enteredCharsDisplayTitle;

    sf::Text livesLeftDisplayTitle;
    sf::Text livesLeftDisplay;

    int possibleWordsOffScreenCount;

    auto spawnWord(const std::string& word) -> void;
    auto updateWordPositions(sf::Time elapsedTime) -> void;
    auto loadRandomWordFromFile() -> void;
    auto checkEnteredWord() -> void;
    auto checkWordOffScreen() -> void;
    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;

};


#endif //PJCPROJ_GAMESCENE_H
