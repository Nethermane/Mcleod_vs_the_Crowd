//
// Created by Bruce on 2019-10-12.
//

#include "EnemyManager.h"

void EnemyManager::update(long long int delta) {
    for (auto enemy: enemies) {
        map.updateEnemyPosition(&enemy, delta);
    }
}

EnemyManager::EnemyManager(const Map &map): map(map) {

}

const std::vector<Enemy> &EnemyManager::getEnemies() const {
    return enemies;
}

