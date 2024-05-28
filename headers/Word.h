//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_WORD_H
#define PJCPROJ_WORD_H

#include <SFML/Graphics.hpp>

class Word : public sf::Drawable {
public:
    Word(const std::string& text, const sf::Font& font, float speed);
    void update(sf::Time elapsedTime);
    bool isOffScreen() const;
    bool matchTyping(const std::string& typed);

private:
    sf::Text wordText;
    float speed;
    std::string typedText;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //PJCPROJ_WORD_H
