//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameOverScene.h"
#include "../headers/GameEngine.h"
#include "../headers/TitleScene.h"
#include "../headers/GameScene.h"

GameOverScene::GameOverScene(GameEngine& engine, int finalScore) : Scene(engine, settings) {
    gameOverBackgroundTexture.loadFromFile("../assets/images/monkiGameOverBg.jpg");
    gameOverBackgroundImage.setTexture(gameOverBackgroundTexture);
    gameOverBackgroundImage.setScale(sf::Vector2f(1, 1));
    gameOverBackgroundImage.setPosition(sf::Vector2f(0, 0));

    gameOverMenuBackground.setSize(sf::Vector2f(800.f, 400.f));
    gameOverMenuBackground.setPosition(sf::Vector2f(gameEngine.getWindow().getSize().x / 2 - 400,
                                                    gameEngine.getWindow().getSize().y / 2 - 200));
    gameOverMenuBackground.setFillColor(sf::Color(64,64,64, 190));

    font.loadFromFile("../assets/fonts/Danfo.ttf");

    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(52);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(sf::Vector2f(
                gameOverMenuBackground.getPosition().x + gameOverMenuBackground.getSize().x / 2 - gameOverText.getLocalBounds().width / 2,
                gameOverMenuBackground.getPosition().y + 30
            ));

    arialFont.loadFromFile("../assets/fonts/arial.ttf");

    scoreDisplay.setFont(font);
    scoreDisplay.setCharacterSize(52);
    scoreDisplay.setString("Score: " + std::to_string(finalScore));
    scoreDisplay.setPosition(sf::Vector2f(
            gameOverMenuBackground.getPosition().x + gameOverMenuBackground.getSize().x/2 - scoreDisplay.getLocalBounds().width/2,
            gameOverMenuBackground.getPosition().y + gameOverText.getLocalBounds().height + 60
            ));

    exitGameButton.setFont(arialFont);
    exitGameButton.setCharacterSize(24);
    exitGameButton.setString("Exit Game");
    exitGameButton.setPosition(sf::Vector2f(
            gameOverMenuBackground.getPosition().x + 30,
            gameOverMenuBackground.getPosition().y + gameOverMenuBackground.getSize().y - exitGameButton.getSize().y - 30
            ));

    returnToTitleButton.setFont(arialFont);
    returnToTitleButton.setCharacterSize(24);
    returnToTitleButton.setString("Return to Title");
    returnToTitleButton.setPosition(sf::Vector2f(
            gameOverMenuBackground.getPosition().x + gameOverMenuBackground.getSize().x - returnToTitleButton.getSize().x - 30,
            gameOverMenuBackground.getPosition().y + gameOverMenuBackground.getSize().y - returnToTitleButton.getSize().y - 30
            ));
}

GameOverScene::~GameOverScene() {}

auto GameOverScene::onUpdate(sf::Time elapsedTime) -> void {
    // Update logic here
}

auto GameOverScene::handleEvent(const sf::Event& event) -> void {
    exitGameButton.handleEvent(event, gameEngine.getWindow());
    returnToTitleButton.handleEvent(event, gameEngine.getWindow());

    if (exitGameButton.isClicked()) {
        gameEngine.getWindow().close();
    }
    if (returnToTitleButton.isClicked()) {
        gameEngine.changeScene(std::make_unique<TitleScene>(gameEngine, gameEngine.getSettings()));
    }
}


auto GameOverScene::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    target.draw(gameOverBackgroundImage, states);
    target.draw(gameOverMenuBackground, states);

    target.draw(gameOverText, states);

    target.draw(scoreDisplay, states);

    target.draw(exitGameButton, states);
    target.draw(returnToTitleButton, states);
}
