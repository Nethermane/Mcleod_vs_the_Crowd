//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWERMANAGER_H
#define FIGHTCLUB_TOWERMANAGER_H

#include <string>

#include "Map.h"
#include "Tower.h"
#include "Upgrade.h"
#include <algorithm>


class ProjectileManager;
class EnemyManager;
class ResourceManager;
/**
 * This class stores all towers and manages the creation of projectiles.
 */
class TowerManager: sf::Drawable {
private:
    std::forward_list<Upgrade> tower1Upgrades, tower2Upgrades, tower3Upgrades, tower4Upgrades;
    std::vector<Tower> towers;
    const Map &map;
    const EnemyManager &enemyManager;
    ProjectileManager &projectileManager;
    const ResourceManager &resourceManager;
    const sf::FloatRect globalBounds;
    sf::CircleShape towerSizeCircle;
public:
    explicit TowerManager(const Map &map, const EnemyManager &enemyManager, ProjectileManager &projectileManager, const ResourceManager &resourceManager, const sf::FloatRect &globalBounds);

    void update(float delta);
    bool upgradeTower(Tower t);
    ///Renders the towers
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void createTower(const sf::Vector2f &position, const TowerType &towerType);

    int getFirstRange(TowerType towerType) const;

    bool isTowerPositionValid(float x, float y);
    bool isTowerPositionValid(sf::Vector2f position);
};


#endif //FIGHTCLUB_TOWERMANAGER_H
