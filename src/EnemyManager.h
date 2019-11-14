//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_ENEMYMANAGER_H
#define FIGHTCLUB_ENEMYMANAGER_H


#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Map.h"

class EnemyManager {
private:
    std::vector<Enemy> enemies;
public:
    std::vector<Enemy> &getEnemies();

private:
    const Map &map;
public:
    void update(float delta);

    explicit EnemyManager(const Map &map);

    void draw(sf::RenderTarget &target, sf::RenderStates states);
};


#endif //FIGHTCLUB_ENEMYMANAGER_H
