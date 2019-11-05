//
// Created by Bruce on 2019-11-04.
//

#ifndef FIGHTCLUB_INGAMEMENU_H
#define FIGHTCLUB_INGAMEMENU_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "ResourceManager.h"
#include "GameStateManager.h"
#include "Tower.h"

class InGameMenu : sf::Drawable {
    ResourceManager &resourceManager;
    GameStateManager &gameStateManager;
    sf::RectangleShape background, outlineMoney, outlineUpgrade, outlineHealth, outlineTower1, outlineTower2, outlineTower3, outlineTower4;
    sf::Text fps_counter, money, cost1, cost2, cost3, cost4, upgrade, healthText;
    sf::Sprite tower1, tower2, tower3, tower4;
    float padding,
            top,
            bottom,
            windowEnd,
            windowStart,
            center_horizontal,
            column1,
            column2,
            row1,
            row2,
            thirdWidth;
public:
    sf::Vector2u playableArea;
    InGameMenu(sf::Vector2u screenSize, const float &percentScreenTake, ResourceManager &resourceManager, GameStateManager &gameStateManager);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void update(const float &delta);

    void selectTower(const Tower &tower);

    void deselectTower();

    void updateHealth();

    void updateMoney();
};


#endif //FIGHTCLUB_INGAMEMENU_H
