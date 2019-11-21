//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include <chrono>
#include "EnemyManager.h"

void EnemyManager::update(float delta) {
    auto enemy = enemies.begin();
    while (enemy != enemies.end()) {
        (*enemy).update(delta);
        if ((*enemy).hasHitEnd()) {
            killedEnemies++;
//            std::cout<<"Enemy hit end! "<<killedEnemies<<std::endl; // testing
            gameStateManager.setHealth(gameStateManager.getHealth() - (*enemy).getDamage());
            enemy = enemies.erase(enemy);
        } else if ((*enemy).getHealth() <= 0) {
            killedEnemies++;
//            std::cout<<"Enemy killed! "<<killedEnemies<<std::endl; // testing
            gameStateManager.setMoney(gameStateManager.getMoney() + (*enemy).getReward());
            enemy = enemies.erase(enemy);
        } else {
            ++enemy;
        }
    }
    if (roundInProgress)
        round();
    else if (!roundInProgress)
        roundOver();
}

EnemyManager::EnemyManager(const Map &map, GameStateManager &gameStateManager, ResourceManager &resourceManager)
        : map(map),
          gameStateManager(
                  gameStateManager),
          resourceManager(
                  resourceManager) {
    simple_rand.seed(static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()));
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
    float enemyDelay = 3.0f / roundNum;
    auto enemy = enemies.begin();
    float lastCheck = clock.getElapsedTime().asSeconds();
    if ((lastCheck >= enemyDelay) && (spawnedEnemies < numEnemies) && (!allSpawned)) {
        makeEnemies();
//        std::cout << "Enemy spawned! " << spawnedEnemies + 1 << std::endl; // testing
//        std::cout << "Killed enemies: " << killedEnemies << std::endl; // testing
        clock.restart();
    }

    if (spawnedEnemies == numEnemies) {
        allSpawned = true;
//        std::cout << "All spawned!" << std::endl; // testing
    }

    if (killedEnemies == numEnemies)
        allKilled = true;
//        std::cout << "All killed!" << std::endl;

    if (allSpawned && allKilled) {
        roundInProgress = false;
    }
}

void EnemyManager::roundOver() {
    int roundNum = gameStateManager.getRound();
    std::cout<<"Round "<<roundNum<<" over!"<<std::endl; // testing - should be a popup GUI window
    killedEnemies = 0;
    allKilled = false;
    spawnedEnemies = 0;
    allSpawned = false;
    gameStateManager.setRound(roundNum + 1);
    roundNum = gameStateManager.getRound();
    std::cout<<"Round "<<roundNum<<" beginning!"<<std::endl;
    roundInProgress = true;
}

void EnemyManager::draw(sf::RenderTarget &target, sf::RenderStates states) {
    for (const auto &enemy: enemies)
        enemy.draw(target, states);
    for(const auto &enemy: enemies)
        if(enemy.isDamaged())
            enemy.drawHealthBar(target, states);
}

void EnemyManager::makeEnemies() {
    spawnedEnemies++;
    addRandomEnemy();
//    for (auto &enemy: enemies) // testing
//        enemy.hit(2);
}

void EnemyManager::addRandomEnemy() {
    auto level = static_cast<int>(simple_rand() % enemyTextures.size() + 1);
    int health = level * 5;
    int damage = level;
    int reward = level;
    int speed = 100;
    enemies.emplace_back(map.begin(), map.end(), enemyTextures[level - 1], healthBarTextures,
                         health, damage, reward, speed);

}