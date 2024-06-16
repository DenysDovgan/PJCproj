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
    increaseSpeedButton.setPosition(sf::Vector2f(430,500));

    // Decrease speed button
    decreaseSpeedButton.setFont(buttonFont);
    decreaseSpeedButton.setCharacterSize(24);
    decreaseSpeedButton.setString("-");
    decreaseSpeedButton.setShapeSize(sf::Vector2f(30,30));
    decreaseSpeedButton.setPosition(sf::Vector2f(380,500));


    // Word speed text
    wordSpeedText.setFont(font);
    wordSpeedText.setCharacterSize(24);
    wordSpeedText.setFillColor(sf::Color::White);
    wordSpeedText.setPosition(100, 500);
    wordSpeed = WordSpeed::MEDIUM;
    updateTextSpeed();

    // Next font button
    nextFontButton.setFont(buttonFont);
    nextFontButton.setCharacterSize(24);
    nextFontButton.setString(">");
    nextFontButton.setShapeSize(sf::Vector2f(30,30));
    nextFontButton.setPosition(sf::Vector2f(430,600));

    // Prev font button
    prevFontButton.setFont(buttonFont);
    prevFontButton.setCharacterSize(24);
    prevFontButton.setString("<");
    prevFontButton.setShapeSize(sf::Vector2f(30,30));
    prevFontButton.setPosition(sf::Vector2f(380,600));
    // Current font text
    wordFontText.setFont(font);
    wordFontText.setCharacterSize(24);
    wordFontText.setString("Font: " + settings.getCurrentFontName());
    wordFontText.setFillColor(sf::Color::White);

    wordFontText.setPosition(sf::Vector2f(100, 600));
    updateTextFont();

    // Next size button
    nextWordSizeButton.setFont(buttonFont);
    nextWordSizeButton.setCharacterSize(24);
    nextWordSizeButton.setString("+");
    nextWordSizeButton.setShapeSize(sf::Vector2f(30,30));
    nextWordSizeButton.setPosition(sf::Vector2f(430,550));

    // Prev size button
    prevWordSizeButton.setFont(buttonFont);
    prevWordSizeButton.setCharacterSize(24);
    prevWordSizeButton.setString("-");
    prevWordSizeButton.setShapeSize(sf::Vector2f(30,30));
    prevWordSizeButton.setPosition(sf::Vector2f(380,550));

    // Text size text
    wordSizeText.setFont(font);
    wordSizeText.setCharacterSize(24);
    wordSizeText.setFillColor(sf::Color::White);
    wordSizeText.setPosition(100, 550);
    wordSize = WordSize::MEDIUM;
    updateTextSize();


}

TitleScene::~TitleScene() {}

auto TitleScene::onUpdate(sf::Time elapsedTime) -> void {};


auto TitleScene::handleEvent(const sf::Event& event) -> void {
    increaseSpeedButton.handleEvent(event, gameEngine.getWindow());
    decreaseSpeedButton.handleEvent(event, gameEngine.getWindow());
    startGameButton.handleEvent(event, gameEngine.getWindow());

    nextWordSizeButton.handleEvent(event, gameEngine.getWindow());
    prevWordSizeButton.handleEvent(event, gameEngine.getWindow());

    nextFontButton.handleEvent(event, gameEngine.getWindow());
    prevFontButton.handleEvent(event, gameEngine.getWindow());

    if (startGameButton.isClicked()) {
        gameEngine.changeScene(std::make_unique<GameScene>(gameEngine, wordSpeed, wordSize, "../assets/wordlist.txt", settings.getFont()));
    }

    if (decreaseSpeedButton.isClicked()) {
        wordSpeed = static_cast<WordSpeed>(std::max(static_cast<int>(wordSpeed) - 50, 50));
        updateTextSpeed();
    }
    if (increaseSpeedButton.isClicked()) {
        wordSpeed = static_cast<WordSpeed>(std::min(static_cast<int>(wordSpeed) + 50, 200));
        updateTextSpeed();
    }

    if (nextWordSizeButton.isClicked()) {
        wordSize = static_cast<WordSize>(std::min(static_cast<int>(wordSize) + 12, 36));
        updateTextSize();
    }

    if (prevWordSizeButton.isClicked()) {
        wordSize = static_cast<WordSize>(std::max(static_cast<int>(wordSize) - 12, 12));
        updateTextSize();
    }


    if (nextFontButton.isClicked()) {
        auto fontPosInVec = settings.getPlaceInVectorByFontName(settings.getCurrentFontName());
        auto fontNames = settings.getFontNames();
        if (fontPosInVec+1 != fontNames.size()){
            settings.setCurrentFontName(settings.getFontNames().at(fontPosInVec + 1));
            settings.setFont(settings.getFonts().at(fontPosInVec+1));
            wordFontText.setString("Font: " + settings.getCurrentFontName());
        }
    }

    if (prevFontButton.isClicked()) {
        auto fontPosInVec = settings.getPlaceInVectorByFontName(settings.getCurrentFontName());
        auto fontNames = settings.getFontNames();
        if (fontPosInVec-1 != -1){
            settings.setCurrentFontName(settings.getFontNames().at(fontPosInVec - 1));
            settings.setFont(settings.getFonts().at(fontPosInVec - 1));
            wordFontText.setString("Font: " + settings.getCurrentFontName());
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
    wordSpeedText.setString(speedString);
}

auto TitleScene::updateTextSize() -> void {
    auto sizeString = std::string();
    switch (wordSize) {
        case WordSize::SMALL: sizeString = "Size: Small"; break;
        case WordSize::MEDIUM: sizeString = "Size: Medium"; break;
        case WordSize::BIG: sizeString = "Size: Big"; break;
    }
    wordSizeText.setString(sizeString);
}

auto TitleScene::updateTextFont() -> void {
    wordFontText.setString("Font: " + settings.getCurrentFontName());
}

auto TitleScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    target.draw(backgroundImage, states);
    target.draw(menuBackground, states);

    target.draw(titleText, states);

    target.draw(startGameButton, states);
    target.draw(increaseSpeedButton, states);
    target.draw(decreaseSpeedButton, states);

    target.draw(wordSizeText, states);
    target.draw(nextWordSizeButton, states);
    target.draw(prevWordSizeButton, states);

    target.draw(startGameText, states);
    target.draw(wordSpeedText, states);

    target.draw(wordFontText, states);
    target.draw(nextFontButton, states);
    target.draw(prevFontButton, states);

}
