//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_TITLESCENE_H
#define PJCPROJ_TITLESCENE_H


#include "Scene.h"

class TitleScene : public Scene {
public:
    TitleScene(GameEngine& engine);
    virtual ~TitleScene();

    void onUpdate(sf::Time elapsedTime) override;
    void handleEvent(const sf::Event& event) override;

private:
    sf::Text titleText;
    sf::Font font;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //PJCPROJ_TITLESCENE_H
