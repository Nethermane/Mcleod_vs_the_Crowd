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
            killedEnemies++;
            gameStateManager.setHealth(gameStateManager.getHealth() - (*enemy).getDamage());
            enemy = enemies.erase(enemy);
        } else if ((*enemy).getHealth() <= 0) {
            killedEnemies++;
            gameStateManager.setMoney(gameStateManager.getMoney() + (*enemy).getReward());
            enemy = enemies.erase(enemy);
        } else {
            ++enemy;
        }
    }
    if (round1)
        round();
    else if (roundFinished)
        roundOver();
}

EnemyManager::EnemyManager(const Map &map, GameStateManager &gameStateManager, ResourceManager &resourceManager)
        : map(map),
          gameStateManager(
                  gameStateManager),
          resourceManager(
                  resourceManager) {
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

const std::vector<Enemy> &EnemyManager::getEnemies() const {
    return enemies;
}

void EnemyManager::round() {
    int roundNum = gameStateManager.getRound();
    int numEnemies = 4 * roundNum + 1;
    int spawnedEnemies = getEnemies().size();
    float enemyDelay = 3.0f / roundNum;
    auto enemy = enemies.begin();
    float lastCheck = clock.getElapsedTime().asSeconds();
    if ((lastCheck >= enemyDelay) && (spawnedEnemies < numEnemies) && (!allSpawned)) {
        makeEnemies();
//        std::cout << "spawned: " << spawnedEnemies + 1 << std::endl; // testing
        clock.restart();
    }

    if (spawnedEnemies == numEnemies)
        allSpawned = true;

    if (allSpawned && (killedEnemies == numEnemies)) {
        round1 = false;
        roundFinished = true;
    }
}

void EnemyManager::roundOver() {
    int roundNum = gameStateManager.getRound();
    std::cout<<"Round "<<roundNum<<" over!"<<std::endl; // testing - should be a popup GUI window
    roundFinished = false;
    gameStateManager.setRound(roundNum + 1);
}

void EnemyManager::draw(sf::RenderTarget &target, sf::RenderStates states) {
    for (const auto &enemy: enemies)
        enemy.draw(target, states);
    for(const auto &enemy: enemies)
        if(enemy.isDamaged())
            enemy.drawHealthBar(target, states);
}

void EnemyManager::makeEnemies() {
    addRandomEnemy();
//    for (auto &enemy: enemies) // testing
//        enemy.hit(2);
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