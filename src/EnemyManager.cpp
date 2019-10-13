//
// Created by Bruce on 2019-10-12.
//

#include "EnemyManager.h"


void EnemyManager::update(long long int delta) {
    for (auto &enemy: enemies) {
        enemy.update(delta);
    }
}

EnemyManager::EnemyManager(const Map &map): map(map) {
    sf::Texture texture;
    if (!texture.loadFromFile("../img/logo.png"))
    {
        exit(1);
    }
    enemies.emplace_back(map.begin(), map.end(), texture);
}

const std::vector<Enemy> &EnemyManager::getEnemies() const {
    return enemies;
}

void EnemyManager::draw(sf::RenderTarget &target, sf::RenderStates states) {
    for(const auto &enemy: enemies)
        enemy.draw(target, states);
}

