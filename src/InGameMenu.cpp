//
// Created by Bruce on 2019-11-04.
//

#include "InGameMenu.h"
#include "GameStateManager.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <SFML/Graphics/Rect.hpp>


void InGameMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(outlineMoney);
    target.draw(outlineUpgrade);
    target.draw(outlineTower1);
    target.draw(outlineTower2);
    target.draw(outlineTower3);
    target.draw(outlineTower4);
    target.draw(healthBar);
    target.draw(outlineHealth);
    target.draw(money);
    target.draw(cost1);
    target.draw(cost2);
    target.draw(cost3);
    target.draw(cost4);
    target.draw(upgrade);
    target.draw(healthText);
    target.draw(tower1);
    target.draw(tower2);
    target.draw(tower3);
    target.draw(tower4);

    target.draw(sound);
    target.draw(options);
    target.draw(pause);
    target.draw(fps_counter);
}


InGameMenu::InGameMenu(sf::Vector2u screenSize, const float &percentScreenTake, ResourceManager &resourceManager,
                       GameStateManager &gameStateManager)
        : resourceManager(resourceManager), gameStateManager(gameStateManager) {
    padding = screenSize.x * 0.02f;
    top = padding;
    bottom = screenSize.y - padding;
    windowEnd = screenSize.x;
    windowStart = (1 - percentScreenTake) * windowEnd;
    center_horizontal = screenSize.x * 0.85f;
    column1 = 0.775f * screenSize.x;
    column2 = 0.925f * screenSize.x;
    row1 = screenSize.y * 0.35f;
    row2 = screenSize.y * 0.65f;
    thirdWidth = (windowEnd - windowStart) / 3.0f;

    background.setFillColor(sf::Color::White);
    background.setOutlineColor(sf::Color::Black);
    background.setSize(sf::Vector2f(screenSize.x * percentScreenTake, screenSize.y));
    background.setPosition(windowStart, 0);


    fps_counter.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    fps_counter.setCharacterSize(24);
    fps_counter.setFillColor(sf::Color::Red);
    fps_counter.setString("0");
    fps_counter.setPosition(fps_counter.getLocalBounds().width, screenSize.y - fps_counter.getLocalBounds().height * 2);

    options.setTexture(*resourceManager.GetTexture(ResourceIdentifier::options));
    options.setScale(
            screenSize.x * 0.025f / options.getLocalBounds().width,
            screenSize.x * 0.025f / options.getLocalBounds().height);
    options.setPosition(0, 0);

    pause.setTexture(*resourceManager.GetTexture(ResourceIdentifier::pause));
    pause.setScale(
            screenSize.x * 0.025f / pause.getLocalBounds().width,
            screenSize.x * 0.025f / pause.getLocalBounds().height);
    pause.setPosition(options.getLocalBounds().width * options.getScale().x, 0);

    sound.setTexture(*resourceManager.GetTexture(ResourceIdentifier::sound));
    sound.setScale(
            screenSize.x * 0.025f / sound.getLocalBounds().width,
            screenSize.x * 0.025f / sound.getLocalBounds().height);
    sound.setPosition(pause.getPosition().x + pause.getLocalBounds().width * pause.getScale().x, 0);


    money.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    money.setCharacterSize(48);
    money.setFillColor(sf::Color::Black);
    money.setString("McClout: " + std::to_string(gameStateManager.getMoney()));
    money.setOrigin(money.getLocalBounds().width / 2, money.getLocalBounds().height / 2);
    money.setPosition(center_horizontal, top);


    outlineMoney.setSize(sf::Vector2f(screenSize.x * 0.25f, money.getLocalBounds().height + padding));
    outlineMoney.setOrigin(outlineMoney.getLocalBounds().width / 2, outlineMoney.getLocalBounds().height / 2);
    outlineMoney.setOutlineColor(sf::Color::Black);
    outlineMoney.setFillColor(sf::Color::Transparent);
    outlineMoney.setOutlineThickness(2);
    outlineMoney.setPosition(money.getPosition().x, money.getPosition().y + money.getLocalBounds().height / 2);


    cost1.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    cost1.setCharacterSize(25);
    cost1.setString("10");
    cost1.setFillColor(sf::Color::Black);
    cost1.setOrigin(cost1.getLocalBounds().width / 2, cost1.getLocalBounds().height / 2);
    cost1.setPosition(column1, row1);

    outlineTower1.setSize(sf::Vector2f(thirdWidth, thirdWidth));
    outlineTower1.setOrigin(outlineTower1.getLocalBounds().width / 2, outlineTower1.getLocalBounds().height / 2);
    outlineTower1.setOutlineColor(sf::Color::Black);
    outlineTower1.setFillColor(sf::Color::Transparent);
    outlineTower1.setOutlineThickness(2);
    outlineTower1.setPosition(cost1.getPosition().x, cost1.getPosition().y - cost1.getLocalBounds().width / 2 -
                                                     outlineTower1.getLocalBounds().height / 2);

    tower1.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod));
    tower1.setScale(
            outlineTower1.getLocalBounds().width / tower1.getLocalBounds().width,
            outlineTower1.getLocalBounds().height / tower1.getLocalBounds().height);
    tower1.setOrigin(tower1.getLocalBounds().width / 2, tower1.getLocalBounds().height / 2);
    tower1.setPosition(outlineTower1.getPosition());


    cost2.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    cost2.setCharacterSize(25);
    cost2.setString("25");
    cost2.setFillColor(sf::Color::Black);
    cost2.setOrigin(cost2.getLocalBounds().width / 2, cost2.getLocalBounds().height / 2);
    cost2.setPosition(column2, row1);

    outlineTower2.setSize(sf::Vector2f(thirdWidth, thirdWidth));
    outlineTower2.setOrigin(outlineTower2.getLocalBounds().width / 2, outlineTower2.getLocalBounds().height / 2);
    outlineTower2.setOutlineColor(sf::Color::Black);
    outlineTower2.setFillColor(sf::Color::Transparent);
    outlineTower2.setOutlineThickness(2);
    outlineTower2.setPosition(cost2.getPosition().x, cost2.getPosition().y - cost2.getLocalBounds().width / 2 -
                                                     outlineTower1.getLocalBounds().height / 2);

    tower2.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod));
    tower2.setScale(
            outlineTower2.getLocalBounds().width / tower2.getLocalBounds().width,
            outlineTower2.getLocalBounds().height / tower2.getLocalBounds().height);
    tower2.setOrigin(tower2.getLocalBounds().width / 2, tower2.getLocalBounds().height / 2);
    tower2.setPosition(outlineTower2.getPosition());

    cost3.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    cost3.setCharacterSize(25);
    cost3.setString("75");
    cost3.setFillColor(sf::Color::Black);
    cost3.setOrigin(cost3.getLocalBounds().width / 2, cost3.getLocalBounds().height / 2);
    cost3.setPosition(column1, row2);

    outlineTower3.setSize(sf::Vector2f(thirdWidth, thirdWidth));
    outlineTower3.setOrigin(outlineTower3.getLocalBounds().width / 2, outlineTower3.getLocalBounds().height / 2);
    outlineTower3.setOutlineColor(sf::Color::Black);
    outlineTower3.setFillColor(sf::Color::Transparent);
    outlineTower3.setOutlineThickness(2);
    outlineTower3.setPosition(cost3.getPosition().x, cost3.getPosition().y - cost3.getLocalBounds().width / 2 -
                                                     outlineTower1.getLocalBounds().height / 2);

    tower3.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod));
    tower3.setScale(
            outlineTower3.getLocalBounds().width / tower3.getLocalBounds().width,
            outlineTower3.getLocalBounds().height / tower3.getLocalBounds().height);
    tower3.setOrigin(tower3.getLocalBounds().width / 2, tower3.getLocalBounds().height / 2);
    tower3.setPosition(outlineTower3.getPosition());


    cost4.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    cost4.setCharacterSize(25);
    cost4.setString("100");
    cost4.setFillColor(sf::Color::Black);
    cost4.setOrigin(cost4.getLocalBounds().width / 2, cost4.getLocalBounds().height / 2);
    cost4.setPosition(column2, row2);

    outlineTower4.setSize(sf::Vector2f(thirdWidth, thirdWidth));
    outlineTower4.setOrigin(outlineTower4.getLocalBounds().width / 2, outlineTower4.getLocalBounds().height / 2);
    outlineTower4.setOutlineColor(sf::Color::Black);
    outlineTower4.setFillColor(sf::Color::Transparent);
    outlineTower4.setOutlineThickness(2);
    outlineTower4.setPosition(cost4.getPosition().x, cost4.getPosition().y - cost4.getLocalBounds().width / 2 -
                                                     outlineTower1.getLocalBounds().height / 2);

    tower4.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod));
    tower4.setScale(
            outlineTower4.getLocalBounds().width / tower4.getLocalBounds().width,
            outlineTower4.getLocalBounds().height / tower4.getLocalBounds().height);
    tower4.setOrigin(tower4.getLocalBounds().width / 2, tower4.getLocalBounds().height / 2);
    tower4.setPosition(outlineTower4.getPosition());

    upgrade.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    upgrade.setCharacterSize(30);
    upgrade.setString("Upgrade");
    upgrade.setFillColor(sf::Color(0, 0, 0, 100));
    upgrade.setOrigin(upgrade.getLocalBounds().width / 2, upgrade.getLocalBounds().height / 2);
    upgrade.setPosition(center_horizontal, screenSize.y * 0.8f);

    outlineUpgrade.setSize(sf::Vector2f(screenSize.x * 0.25f, upgrade.getLocalBounds().height + padding));
    outlineUpgrade.setOrigin(outlineUpgrade.getLocalBounds().width / 2, outlineUpgrade.getLocalBounds().height / 2);
    outlineUpgrade.setOutlineColor(sf::Color::Black);
    outlineUpgrade.setFillColor(sf::Color(169, 169, 169, 100));
    outlineUpgrade.setOutlineThickness(2);
    outlineUpgrade.setPosition(upgrade.getPosition().x, upgrade.getPosition().y + upgrade.getLocalBounds().height / 2);

    healthText.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    healthText.setCharacterSize(50);
    healthText.setString(
            std::to_string(gameStateManager.getMaxHealth()) + "/" + std::to_string(gameStateManager.getHealth()));
    healthText.setFillColor(sf::Color::Black);
    healthText.setOrigin(healthText.getLocalBounds().width / 2, healthText.getLocalBounds().height / 2);
    healthText.setPosition(center_horizontal, screenSize.y * 0.9f);

    healthBar.setShowBackgroundAndFrame(true);
    healthBar.setSize(sf::Vector2f(screenSize.x * 0.25f, healthText.getLocalBounds().height + padding));
    healthBar.setOrigin(healthBar.getLocalBounds().width / 2, healthBar.getLocalBounds().height / 2);
    healthBar.setPosition(healthText.getPosition().x, healthText.getPosition().y + healthText.getLocalBounds().height/2);
    healthBar.setColor(sf::Color(124, 252, 0, 255));
    healthBar.setBackgroundColor(sf::Color(220, 20, 60, 255));

    outlineHealth.setSize(sf::Vector2f(healthBar.getSize().x, healthBar.getSize().y));
    outlineHealth.setOrigin(outlineHealth.getLocalBounds().width / 2, outlineHealth.getLocalBounds().height / 2);
    outlineHealth.setOutlineColor(sf::Color::Black);
    outlineHealth.setFillColor(sf::Color::Transparent);
    outlineHealth.setOutlineThickness(2);
    outlineHealth.setPosition(healthBar.getPosition().x -1, healthBar.getPosition().y-1);
}

void InGameMenu::update(const float &delta) {
    fps_counter.setString(std::to_string(static_cast<int>(1.0f / delta)));
    updateHealth();
    updateMoney();
}

void InGameMenu::selectTower(const Tower &tower) {
    upgrade.setFillColor(sf::Color(0, 0, 0, 255));
    outlineUpgrade.setFillColor(sf::Color(169, 169, 169, 255));

}

void InGameMenu::deselectTower() {
    upgrade.setFillColor(sf::Color(0, 0, 0, 100));
    outlineUpgrade.setFillColor(sf::Color(169, 169, 169, 100));
}

void InGameMenu::updateHealth() {
    int currHealth = gameStateManager.getHealth();
    if(currHealth < 0)
        healthText.setString("0/" + std::to_string(gameStateManager.getMaxHealth()));
    else
        healthText.setString(std::to_string(currHealth) + "/" + std::to_string(gameStateManager.getMaxHealth()));
    healthBar.setRatio(currHealth * 1.0f / gameStateManager.getMaxHealth());
}

void InGameMenu::updateMoney() {
    money.setString("McClout: " + std::to_string(gameStateManager.getMoney()));
    money.setOrigin(money.getLocalBounds().width / 2, money.getLocalBounds().height / 2);
}

MenuButtonPresses InGameMenu::menuClick(sf::Vector2i clickPosition) {
    sf::Vector2f clickPositionFloat = sf::Vector2f(clickPosition);
    if (outlineTower1.getGlobalBounds().contains(clickPositionFloat))
        return Tower1;
    else if (outlineTower2.getGlobalBounds().contains(clickPositionFloat))
        return Tower2;
    else if (outlineTower3.getGlobalBounds().contains(clickPositionFloat))
        return Tower3;
    else if (outlineTower4.getGlobalBounds().contains(clickPositionFloat))
        return Tower4;
    else if (outlineUpgrade.getGlobalBounds().contains(clickPositionFloat))
        return Upgrade;
    else if (pause.getGlobalBounds().contains(clickPositionFloat))
        return Pause;
    else if (options.getGlobalBounds().contains(clickPositionFloat))
        return Options;
    else if (sound.getGlobalBounds().contains(clickPositionFloat))
        if (muteState) {
            sound.setTexture(*resourceManager.GetTexture(ResourceIdentifier::sound));
            muteState = !muteState;
            return UnMute;
        } else {
            sound.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mute));
            muteState = !muteState;
            return Mute;
        }
    else if (background.getGlobalBounds().contains(clickPositionFloat)) {
            return MenuBackground;
    } else
        return None;


}
