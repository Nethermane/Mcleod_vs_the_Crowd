//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWERMANAGER_H
#define FIGHTCLUB_TOWERMANAGER_H

#include <string>

#include "Map.h"
#include "Tower.h"
#include "Upgrade.h"
#include "EnemyManager.h"
#include "ProjectileManager.h"

using std::string;
#include <algorithm>

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
public:
    explicit TowerManager(const Map &map, const EnemyManager &enemyManager, ProjectileManager &projectileManager, const ResourceManager &resourceManager, const sf::FloatRect &globalBounds);

    void update(float delta);
    bool addTower(Tower t);
    bool upgradeTower(Tower t);
    ///Renders the towers
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void createTower(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f &position, const TowerType &towerType);
};


#endif //FIGHTCLUB_TOWERMANAGER_H
