//
// Created by Bruce on 2019-10-12.
//


#include "TowerManager.h"

void TowerManager::update(float delta) {
    for (auto &tower: towers) {
        tower.update(delta, enemyManager.getEnemies(), [](Enemy e) {});
    }
}

TowerManager::TowerManager(const Map &map, const EnemyManager &enemyManager, ProjectileManager &projectileManager)
        : map(map), enemyManager(enemyManager), projectileManager(projectileManager) {
    tower1Upgrades.push_front(Upgrade(4000, 0.1, 4, 250, 100, 12));
    tower1Upgrades.push_front(Upgrade(2000, 0.2, 3, 100, 10, 8));
    tower1Upgrades.push_front(Upgrade(1500, 0.25, 2, 50, 10, 4));
    tower1Upgrades.push_front(Upgrade(1250, 0.5, 1, 25, 10, 2));
    tower1Upgrades.push_front(Upgrade(1000, 1, 0, 10, 10, 1));
}

void TowerManager::createTower(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f &position,
                               const TowerType &towerType) {
    switch (towerType) {
        case TowerType::Tower1:
            towers.emplace_back(texture, position, tower1Upgrades.begin(), tower1Upgrades.end());
            break;
        case TowerType::Tower2:
            towers.emplace_back(texture, position, tower2Upgrades.begin(), tower2Upgrades.end());
            break;
        case TowerType::Tower3:
            towers.emplace_back(texture, position, tower3Upgrades.begin(), tower3Upgrades.end());
            break;
        case TowerType::Tower4:
            towers.emplace_back(texture, position, tower4Upgrades.begin(), tower4Upgrades.end());
            break;
        default:
            throw std::runtime_error("Non recognized tower created");
    }

}

bool TowerManager::addTower(Tower t) {
    this->towers.push_back(t);
    return true;
}
void TowerManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const auto &tower: towers)
        tower.draw(target, states);
}

