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

    void onUpdate(sf::Time elapsedTime) override;
    void handleEvent(const sf::Event& event) override;

private:
    std::vector<Word> words;
    sf::Font font;
    void spawnWord();
    void handleTyping(const std::string& typed);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //PJCPROJ_GAMESCENE_H
