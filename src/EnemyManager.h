//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_ENEMYMANAGER_H
#define FIGHTCLUB_ENEMYMANAGER_H


#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Map.h"
#include "GameStateManager.h"
#include "ResourceManager.h"

class EnemyManager {
private:
    std::vector<Enemy> enemies;
    GameStateManager &gameStateManager;
    ResourceManager &resourceManager;
    std::vector<std::shared_ptr<sf::Texture>> healthBarTextures;
    std::vector<std::shared_ptr<sf::Texture>> enemyTextures;
    const Map &map;
    void addRandomEnemy();
public:
    const std::vector<Enemy> &getEnemies() const;

public:
    void update(float delta);

    explicit EnemyManager(const Map &map, GameStateManager &gameStateManager, ResourceManager &resourceManager);

    void loadEnemyTextures();
    void draw(sf::RenderTarget &target, sf::RenderStates states);
    void makeEnemies();
};


#endif //FIGHTCLUB_ENEMYMANAGER_H
