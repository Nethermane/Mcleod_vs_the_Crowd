//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include "EnemyManager.h"


void EnemyManager::update(float delta) {
    auto enemy = enemies.begin();
    while (enemy != enemies.end()) {
        (*enemy).update(delta);
        if ((*enemy).hasHitEnd()) {
            gameStateManager.setHealth(gameStateManager.getHealth() - (*enemy).getDamage());
            enemy = enemies.erase(enemy);
        } else if ((*enemy).getHealth() <= 0) {
            gameStateManager.setMoney(gameStateManager.getMoney() + (*enemy).getReward());
            enemy = enemies.erase(enemy);
        } else {
            ++enemy;
        }
    }
}

EnemyManager::EnemyManager(const Map &map, GameStateManager &gameStateManager, ResourceManager &resourceManager)
        : map(map),
          gameStateManager(
                  gameStateManager),
          resourceManager(
                  resourceManager) {
}

const std::vector<Enemy> &EnemyManager::getEnemies() const {
    return enemies;
}

void EnemyManager::draw(sf::RenderTarget &target, sf::RenderStates states) {
    for (const auto &enemy: enemies)
        enemy.draw(target, states);
}

void EnemyManager::makeEnemies() {
    for (int i = 1; i < 5; i++) {
        enemies.emplace_back(map.begin(), map.end(), resourceManager.GetTexture(ResourceIdentifier::enemy),
                             healthBarTextures, 10+i, 10, 10, 20*i + 100);
    }
}

void EnemyManager::loadHealthBarTextures() {
    healthBarTextures.clear();
    healthBarTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::HealthF));
    healthBarTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::HealthC));
    healthBarTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::HealthB));
    healthBarTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::HealthA));
}


