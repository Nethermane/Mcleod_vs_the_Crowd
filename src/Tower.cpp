//
// Created by Bruce on 2019-10-12.
//

#include "Tower.h"
#include "Upgrade.h"
#include <SFML/Graphics.hpp>


Tower::Tower(sf::Texture* Texture, const sf::Vector2f position, towerType type, int damage, int range, const sf::Vector2f size):
    towerPosition(position), towerDamage(damage), towerSize(size)

{

    ///Sprite handling
    towerSprite = sf::Sprite(*Texture);
    towerSprite.setPosition(position);

    //set parameters
    upgradePrice = 5;
    clicked = false;
    direction = 'e'; //east

}

towerType Tower::getTowerType() const{
    return this->type;
}

sf::Vector2f Tower::getPosition() const {
    return towerPosition;
}

int Tower::getUpgradeCost() const {
    return (*nextUpgrade).upgradeCost;
}

char Tower::getMode() const{
    return mode;
}

char Tower::getDirection() const {
    return direction;

}
void Tower:: setPosition(sf::Vector2f position){
    towerSprite.setPosition(position);
}

void Tower::setMode(char mode){
    mode = mode;
    // f= fight, n = do not fight
}


void Tower::render(sf::RenderWindow& window){
    window.draw(this->towerSprite);
}


bool Tower::canUpgrade() const {
    return nextUpgrade != upgradeEnd;
}


void Tower::click(){
    this->clicked = true;
}

void Tower::upgrade() {
    auto upgrade = *nextUpgrade;
    range = upgrade.range;
    attackSpeed = upgrade.attackSpeed;
    level = upgrade.level;
    cost = upgrade.cost;
    nextUpgrade = std::next(nextUpgrade, 1);
}


void Tower::setDirection(char direction){
    direction = direction;
            //direction = n,s,e,w
}




