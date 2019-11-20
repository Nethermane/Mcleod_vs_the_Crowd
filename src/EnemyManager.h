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

///Class for managing all enemies, should only have a single instance
class EnemyManager {
private:
    std::vector<Enemy> enemies;
    GameStateManager &gameStateManager;
    ResourceManager &resourceManager;
    std::vector<std::shared_ptr<sf::Texture>> healthBarTextures;
    std::vector<std::shared_ptr<sf::Texture>> enemyTextures;
    const Map &map;
    sf::Clock clock;
    ///Generates a random enemy based on magic numbers
    void addRandomEnemy();

    ///Keeps track of enemy rounds/waves to ensure difficulty increases as level progresses.
    void round();

    ///Ends round.
    void roundOver();

    bool round1 = true;
    bool roundFinished = false;
    bool allSpawned = false;
    int killedEnemies = 0;
public:
    ///@returns list of all currently alive enemies
    const std::vector<Enemy> &getEnemies() const;
    ///Updates all enemies. Lowers health if enemy reach end. Adds money if enemy killed.
    void update(float delta);

    ///Constructor, adds textures to enemy/healthbar lists.
    explicit EnemyManager(const Map &map, GameStateManager &gameStateManager, ResourceManager &resourceManager);

    ///Draws all enemies and their health bars
    void draw(sf::RenderTarget &target, sf::RenderStates states);

    ///Temp testing method that releases a single enemy
    void makeEnemies();
};


#endif //FIGHTCLUB_ENEMYMANAGER_H
