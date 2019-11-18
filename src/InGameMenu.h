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
#include "SelbaWard/ProgressBar.hpp"

enum class MenuButtonPresses {
    None, Tower1, Tower2, Tower3, Tower4, Upgrade, Pause, Options, Mute, UnMute, MenuBackground

};

class InGameMenu : sf::Drawable {
private:
    ResourceManager &resourceManager;
    GameStateManager &gameStateManager;
    sf::RectangleShape background, outlineMoney, outlineRound, outlineUpgrade, outlineHealth, outlineTower1, outlineTower2, outlineTower3, outlineTower4;
    sf::Text fps_counter, money, round, cost1, cost2, cost3, cost4, upgrade, healthText;
    sf::Sprite tower1, tower2, tower3, tower4, pause, sound, options;
    sw::ProgressBar healthBar;
    Tower *selectedTower;
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
    bool muteState = false;
    void updateHealth();

    void updateMoney();

    void updateRound();

    void updateUpgrade();
public:
    InGameMenu(sf::Vector2u screenSize, const float &percentScreenTake, ResourceManager &resourceManager,
               GameStateManager &gameStateManager);

    ///Renders all in game menu items
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    ///Updates ui components based on game sate
    void update(const float &delta);

    ///Return what was clicked if clicking it is allowed
    MenuButtonPresses menuClick(sf::Vector2i clickPosition);

    ///Selects a tower, updates the ui component
    ///@param tower the tower that is being selected
    void selectTower(Tower &tower);

    ///Clear the currently selected tower
    void deselectTower();

    Tower *getSelectedTower() const;
};


#endif //FIGHTCLUB_INGAMEMENU_H
