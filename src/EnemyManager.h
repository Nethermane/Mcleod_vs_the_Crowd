//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_ENEMYMANAGER_H
#define FIGHTCLUB_ENEMYMANAGER_H


#include <vector>
#include "Enemy.h"
#include "Map.h"

class EnemyManager {
private:
    std::vector<Enemy> enemies;
public:
    const std::vector<Enemy> &getEnemies() const;

private:
    const Map &map;
public:
    void update(long long int delta);

    explicit EnemyManager(const Map &map);
};


#endif //FIGHTCLUB_ENEMYMANAGER_H
