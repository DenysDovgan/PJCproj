//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_GAMESCENE_H
#define PJCPROJ_GAMESCENE_H


#include <vector>
#include "Scene.h"
#include "Word.h"

class GameScene : public Scene {
public:
    GameScene(GameEngine& engine);
    virtual ~GameScene();

    auto onUpdate(sf::Time elapsedTime) -> void override;
    auto handleEvent(const sf::Event& event) -> void override;

private:
    std::vector<Word> words;
    sf::Font font;
    auto spawnWord(auto word) -> void;
    auto handleTyping(const std::string& typed) -> void;
    auto loadWordsFromFile(const std::string& wordListLocation) -> void;

    auto draw(sf::RenderTarget& target, sf::RenderStates states) const -> void override;

};


#endif //PJCPROJ_GAMESCENE_H
