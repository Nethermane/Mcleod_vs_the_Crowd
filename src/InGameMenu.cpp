//
// Created by Bruce on 2019-11-04.
//

#include "InGameMenu.h"


void InGameMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background, states);
    target.draw(outlineMoney, states);
    target.draw(outlineRound, states);
    target.draw(outlineUpgrade, states);
    target.draw(outlineTower1, states);
    target.draw(outlineTower2, states);
    target.draw(outlineTower3, states);
    target.draw(outlineTower4, states);
    target.draw(healthBar, states);
    target.draw(outlineHealth, states);
    target.draw(money, states);
    target.draw(round, states);
    target.draw(cost1, states);
    target.draw(cost2, states);
    target.draw(cost3, states);
    target.draw(cost4, states);
    target.draw(upgrade, states);
    target.draw(healthText, states);
    target.draw(tower1, states);
    target.draw(tower2, states);
    target.draw(tower3, states);
    target.draw(tower4, states);

    target.draw(sound, states);
    target.draw(options, states);
    target.draw(pause, states);
    target.draw(fps_counter, states);
    target.draw(mouse, states);
    if(selectedTowerType != TowerType::None)
        target.draw(range, states);
}


InGameMenu::InGameMenu(sf::Vector2u screenSize, const float &percentScreenTake, ResourceManager &resourceManager,
                       GameStateManager &gameStateManager, TowerManager &towerManager)
        : resourceManager(resourceManager), gameStateManager(gameStateManager),
          mouse(*resourceManager.GetTexture(ResourceIdentifier::pointer)), towerManager(towerManager) {
    mouse.setOrigin(mouse.getGlobalBounds().width/2, mouse.getGlobalBounds().height/2);
    selectedTower = nullptr;
    range.setFillColor(sf::Color(255, 255, 255, 128));
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

    round.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    round.setCharacterSize(48);
    round.setFillColor(sf::Color::Black);
    round.setString("Round: " + std::to_string(gameStateManager.getRound()));
    round.setOrigin(round.getLocalBounds().width / 2, round.getLocalBounds().height / 2);
    round.setPosition(center_horizontal, outlineRound.getPosition().y+round.getLocalBounds().height*4+padding);


    outlineRound.setSize(sf::Vector2f(screenSize.x * 0.25f, round.getLocalBounds().height + padding));
    outlineRound.setOrigin(outlineRound.getLocalBounds().width / 2, outlineRound.getLocalBounds().height / 2);
    outlineRound.setOutlineColor(sf::Color::Black);
    outlineRound.setFillColor(sf::Color::Transparent);
    outlineRound.setOutlineThickness(2);
    outlineRound.setPosition(round.getPosition().x, round.getPosition().y + round.getLocalBounds().height / 2);

    cost1.setFont(*resourceManager.GetFont(ResourceIdentifier::apex));
    cost1.setCharacterSize(25);
    cost1.setString(std::to_string(static_cast<int>(TowerType::Tower1)));
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
    cost2.setString(std::to_string(static_cast<int>(TowerType::Tower2)));
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
    cost3.setString(std::to_string(static_cast<int>(TowerType::Tower3)));
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
    cost4.setString(std::to_string(static_cast<int>(TowerType::Tower4)));
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
    healthBar.setPosition(healthText.getPosition().x,
                          healthText.getPosition().y + healthText.getLocalBounds().height / 2);
    healthBar.setColor(sf::Color(124, 252, 0, 255));
    healthBar.setBackgroundColor(sf::Color(220, 20, 60, 255));

    outlineHealth.setSize(sf::Vector2f(healthBar.getSize().x, healthBar.getSize().y));
    outlineHealth.setOrigin(outlineHealth.getLocalBounds().width / 2, outlineHealth.getLocalBounds().height / 2);
    outlineHealth.setOutlineColor(sf::Color::Black);
    outlineHealth.setFillColor(sf::Color::Transparent);
    outlineHealth.setOutlineThickness(2);
    outlineHealth.setPosition(healthBar.getPosition().x - 1, healthBar.getPosition().y - 1);
}

void InGameMenu::update(const float &delta, const sf::Vector2f &mousePos) {
    mouse.setPosition(mousePos);
    range.setPosition(mousePos);
    fps_counter.setString(std::to_string(static_cast<int>(1.0f / delta)));
    if(selectedTowerType != TowerType::None) {
        if(towerManager.isTowerPositionValid(mousePos) && menuPosition(mousePos) == MenuButtonPresses::None) {
            range.setFillColor(sf::Color(255, 255, 255, 128));
        } else {
            range.setFillColor(sf::Color(255, 0, 0, 128));
        }
    }
    updateHealth();
    updateMoney();
    updateUpgrade();
    updateRound();
}

void InGameMenu::selectTower(Tower &tower) {
    selectedTower = &tower;

}

void InGameMenu::deselectTower() {
    selectedTower = nullptr;
}

void InGameMenu::updateUpgrade() {
    if (selectedTower != nullptr && (*selectedTower).canUpgrade() &&
        gameStateManager.getMoney() >= (*selectedTower).getUpgradeCost())
        outlineUpgrade.setFillColor(sf::Color(169, 169, 169, 255));
    else
        outlineUpgrade.setFillColor(sf::Color(169, 169, 169, 100));

}

void InGameMenu::updateRound() {
    round.setString("Round: " + std::to_string(gameStateManager.getRound()));
}


void InGameMenu::updateHealth() {
    int currHealth = gameStateManager.getHealth();
    if (currHealth < 0)
        healthText.setString("0/" + std::to_string(gameStateManager.getMaxHealth()));
    else
        healthText.setString(std::to_string(currHealth) + "/" + std::to_string(gameStateManager.getMaxHealth()));
    healthBar.setRatio(currHealth * 1.0f / gameStateManager.getMaxHealth());
}

void InGameMenu::updateMoney() {
    money.setString("McClout: " + std::to_string(gameStateManager.getMoney()));
    money.setOrigin(money.getLocalBounds().width / 2, money.getLocalBounds().height / 2);
}

MenuButtonPresses InGameMenu::menuPosition(sf::Vector2f clickPosition) {
    if (outlineTower1.getGlobalBounds().contains(clickPosition))
        return MenuButtonPresses::Tower1;
    else if (outlineTower2.getGlobalBounds().contains(clickPosition))
        return MenuButtonPresses::Tower2;
    else if (outlineTower3.getGlobalBounds().contains(clickPosition))
        return MenuButtonPresses::Tower3;
    else if (outlineTower4.getGlobalBounds().contains(clickPosition))
        return MenuButtonPresses::Tower4;
    else if (outlineUpgrade.getGlobalBounds().contains(clickPosition))
        return MenuButtonPresses::Upgrade;
    else if (pause.getGlobalBounds().contains(clickPosition))
        return MenuButtonPresses::Pause;
    else if (options.getGlobalBounds().contains(clickPosition))
        return MenuButtonPresses::Options;
    else if (sound.getGlobalBounds().contains(clickPosition))
        if (muteState) {
            return MenuButtonPresses::UnMute;
        } else {
            return MenuButtonPresses::Mute;
        }
    else if (background.getGlobalBounds().contains(clickPosition)) {
        return MenuButtonPresses::MenuBackground;
    } else
        return MenuButtonPresses::None;


}

Tower *InGameMenu::getSelectedTower() const {
    return selectedTower;
}

void InGameMenu::setSelectedTowerType(TowerType type) {
    selectedTowerType = type;
    if (selectedTowerType != TowerType::None) {
        switch (selectedTowerType) {
            case TowerType::Tower1:
                mouse.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod), true);
                range.setRadius(towerManager.getFirstRange(TowerType::Tower1));
                break;
            case TowerType::Tower2:
                mouse.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod), true);
                range.setRadius(towerManager.getFirstRange(TowerType::Tower2));
                break;
            case TowerType::Tower3:
                mouse.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod), true);
                range.setRadius(towerManager.getFirstRange(TowerType::Tower3));
                break;
            case TowerType::Tower4:
                mouse.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod), true);
                range.setRadius(towerManager.getFirstRange(TowerType::Tower4));
                break;
            default:
                break;
        }
        mouse.setOrigin(mouse.getLocalBounds().width / 2, mouse.getLocalBounds().height / 2);
        mouse.setScale(constants::towerSizeMod, constants::towerSizeMod);
        range.setOrigin(range.getLocalBounds().width / 2, range.getLocalBounds().height / 2);
    } else {
        mouse.setTexture( *resourceManager.GetTexture(ResourceIdentifier::pointer), true);
        mouse.setOrigin(mouse.getLocalBounds().width / 2, mouse.getLocalBounds().height / 2);
    }
}

TowerType InGameMenu::getSelectedTowerType() const {
    return selectedTowerType;
}

void InGameMenu::setUnMute() {
    sound.setTexture(*resourceManager.GetTexture(ResourceIdentifier::sound));
    muteState = !muteState;
}

void InGameMenu::setMute() {
    sound.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mute));
    muteState = !muteState;
}
