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
    for(const auto &enemy: enemies)
        enemy.getHealthBar().draw(target,states);
}

void EnemyManager::makeEnemies() {
    addRandomEnemy();
}

void EnemyManager::loadEnemyTextures() {
    enemyTextures.clear();
    enemyTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::enemy_1));
    enemyTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::enemy_2));
    enemyTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::enemy_3));
    enemyTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::enemy_4));
    enemyTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::enemy_5));
    healthBarTextures.clear();
    healthBarTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::HealthF));
    healthBarTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::HealthC));
    healthBarTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::HealthB));
    healthBarTextures.push_back(resourceManager.GetTexture(ResourceIdentifier::HealthA));
}

void EnemyManager::addRandomEnemy() {
    int level = static_cast<int>(rand() % enemyTextures.size() + 1);
    int health = level * 5;
    int damage = level;
    int reward = level;
    int speed = 100;
    enemies.emplace_back(map.begin(), map.end(), enemyTextures[level - 1], healthBarTextures,
                         health, damage, reward, speed);
}


