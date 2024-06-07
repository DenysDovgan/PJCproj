//
// Created by s30460 on 2024-05-28.
//

#include <iostream>
#include "../headers/TitleScene.h"
#include "../headers/GameEngine.h"
#include "../headers/GameScene.h"

TitleScene::TitleScene(GameEngine& engine, Settings& settings) : Scene(engine, settings) {


    // Menu buttons background
    menuBackground.setSize(sf::Vector2f(400.f, 600.f));
    menuBackground.setPosition(80, 180);
    menuBackground.setFillColor(sf::Color(64,64,64, 190));

    // Background image
    backgroundTexture.loadFromFile("../assets/images/monkibg2.jpg");
    backgroundImage.setTexture(backgroundTexture);
    backgroundImage.setScale(1, 1);
    backgroundImage.setPosition(0, 0);

    // Game title
    font.loadFromFile("../assets/fonts/Danfo.ttf");

    titleText.setFont(font);
    titleText.setString("MONKI TYPER");
    titleText.setCharacterSize(52);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(110 , 200);

    // Button Font
    buttonFont.loadFromFile("../assets/fonts/arial.ttf");

    // NewGame button
    startGameButton.setFont(font);
    startGameButton.setCharacterSize(30);
    startGameButton.setString("New Game");
    startGameButton.setPosition(sf::Vector2f(menuBackground.getPosition().x + 30,300));

    // Increase speed button
    increaseSpeedButton.setFont(buttonFont);
    increaseSpeedButton.setCharacterSize(24);
    increaseSpeedButton.setString("+");
    increaseSpeedButton.setShapeSize(sf::Vector2f(30,30));
    increaseSpeedButton.setPosition(sf::Vector2f(350,500));

    // Decrease speed button
    decreaseSpeedButton.setFont(buttonFont);
    decreaseSpeedButton.setCharacterSize(24);
    decreaseSpeedButton.setString("-");
    decreaseSpeedButton.setShapeSize(sf::Vector2f(30,30));
    decreaseSpeedButton.setPosition(sf::Vector2f(400,500));


    // Word speed text
    speedText.setFont(font);
    speedText.setCharacterSize(24);
    speedText.setFillColor(sf::Color::White);
    speedText.setPosition(100, 500);
    wordSpeed = WordSpeed::MEDIUM;
    updateTextSpeed();

    nextFontButton.setFont(buttonFont);
    nextFontButton.setCharacterSize(24);
    nextFontButton.setString(">");
    nextFontButton.setShapeSize(sf::Vector2f(30,30));
    nextFontButton.setPosition(sf::Vector2f(400,600));

    prevFontButton.setFont(buttonFont);
    prevFontButton.setCharacterSize(24);
    prevFontButton.setString("<");
    prevFontButton.setShapeSize(sf::Vector2f(30,30));
    prevFontButton.setPosition(sf::Vector2f(350,600));

    fontText.setFont(font);
    fontText.setCharacterSize(24);
    fontText.setString("Font: " + settings.getCurrentFontName());
    fontText.setFillColor(sf::Color::White);
    fontText.setPosition(sf::Vector2f(100, 600));
    updateTextFont();

}

TitleScene::~TitleScene() {}

auto TitleScene::onUpdate(sf::Time elapsedTime) -> void {};


auto TitleScene::handleEvent(const sf::Event& event) -> void {
    increaseSpeedButton.handleEvent(event, gameEngine.getWindow());
    decreaseSpeedButton.handleEvent(event, gameEngine.getWindow());
    startGameButton.handleEvent(event, gameEngine.getWindow());

    nextFontButton.handleEvent(event, gameEngine.getWindow());
    prevFontButton.handleEvent(event, gameEngine.getWindow());

    if (startGameButton.isClicked()) {
        gameEngine.changeScene(std::make_unique<GameScene>(gameEngine, wordSpeed, "../assets/wordlist.txt", settings.getFont()));
    }
    if (decreaseSpeedButton.isClicked()) {
        wordSpeed = static_cast<WordSpeed>(std::max(static_cast<int>(wordSpeed) - 50, 50));
        updateTextSpeed();
    }
    if (increaseSpeedButton.isClicked()) {
        wordSpeed = static_cast<WordSpeed>(std::min(static_cast<int>(wordSpeed) + 50, 200));
        updateTextSpeed();
    }

    auto fontIter = settings.getIteratorByFontName(settings.getCurrentFontName());
    auto fontsEnd = settings.getFonts().end();

    if (nextFontButton.isClicked()) {
        auto nextFontIter = std::next(fontIter);
        if (nextFontIter != fontsEnd) {
            settings.setCurrentFontName(nextFontIter->first);
            settings.setFont(nextFontIter->second);
            updateTextFont();
            std::cout << "Next font: " << nextFontIter->first << std::endl;
        } else {
            std::cout << "Reached the end of the font list." << std::endl;
        }
    }

    if (prevFontButton.isClicked()) {
        auto fontIter = settings.getIteratorByFontName(settings.getCurrentFontName());



        if (fontIter != settings.getFonts().begin()) {
            --fontIter;
            settings.setCurrentFontName(fontIter->first);
            settings.setFont(fontIter->second);
            updateTextFont();
        } else if (fontIter == settings.getFonts().begin()) {
            std::cout << "Reached the beginning of the font list." << std::endl;
        }
    }
}

auto TitleScene::updateTextSpeed() -> void {
    auto speedString = std::string();
    switch (wordSpeed) {
        case WordSpeed::SLOW: speedString = "Speed: Slow"; break;
        case WordSpeed::MEDIUM: speedString = "Speed: Medium"; break;
        case WordSpeed::FAST: speedString = "Speed: Fast"; break;
        case WordSpeed::IMPOSSIBLE: speedString = "Speed: Impossible"; break;
    }
    speedText.setString(speedString);
}
auto TitleScene::updateTextFont() -> void {
    fontText.setString("Font: " + settings.getCurrentFontName());
}

auto TitleScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    target.draw(backgroundImage, states);
    target.draw(menuBackground, states);

    target.draw(titleText, states);

    target.draw(startGameButton, states);
    target.draw(increaseSpeedButton, states);
    target.draw(decreaseSpeedButton, states);

    target.draw(startGameText, states);
    target.draw(speedText, states);

    target.draw(fontText, states);
    target.draw(nextFontButton, states);
    target.draw(prevFontButton, states);

}
