//
// Created by Bruce on 2019-10-12.
//


#include "TowerManager.h"
#include "Upgrade.h"
#include "Tower.h"

#include <string>

void TowerManager::update(float delta) {

}

TowerManager::TowerManager(const Map &map): map(map) {
    tower1Upgrades.push_front(Upgrade(400, 50, 4, 250, 100));
    tower1Upgrades.push_front(Upgrade(200, 35, 3, 100, 10));
    tower1Upgrades.push_front(Upgrade(150, 20, 2, 50, 10));
    tower1Upgrades.push_front(Upgrade(125, 10, 1, 25, 10));
    tower1Upgrades.push_front(Upgrade(100, 5, 0, 10, 10));
}

Tower* TowerManager::createTower(sf:: Vector2f position, towerType type){
    Tower* tower;
    sf::Texture* texture = texture;
    tower = new Tower(texture, position, type, 20, 150, sf::Vector2f(120, 120))
    return tower;


}

