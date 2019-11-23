//
// Created by Bruce on 2019-10-12.
//


#include <iostream>
#include "TowerManager.h"
#include "ProjectileManager.h"
#include "RectangularBoundaryCollision.h"
#include "EnemyManager.h"
#include "MathHelpers.h"

void TowerManager::update(float delta) {
    for (auto &tower: towers) {
        tower.update(delta, enemyManager.getEnemies(), [&](Tower t, Enemy e, float angle) {
            projectileManager.addProjectile(t.getProjectileSpeed(), t.getDamage(),
                                            angle,
                                            t.getPosition(),
                                            resourceManager.GetTexture(ResourceIdentifier::HealthA),
                                            globalBounds);//speed damage angle position texture global bounds
        });
    }
}

TowerManager::TowerManager(const Map &map, const EnemyManager &enemyManager, ProjectileManager &projectileManager,
                           const ResourceManager &resourceManager, const sf::FloatRect &globalBounds)
        : map(map), enemyManager(enemyManager), projectileManager(projectileManager), resourceManager(resourceManager),globalBounds(globalBounds),
          towerSizeCircle((*resourceManager.GetTexture(ResourceIdentifier::mcleod)).getSize().x * constants::towerSizeMod){
    towerSizeCircle.setScale(constants::towerSizeMod,constants::towerSizeMod);
    towerSizeCircle.setOrigin(towerSizeCircle.getRadius(), towerSizeCircle.getRadius());
    //basic
    tower1Upgrades.push_front(Upgrade(800, 0.9, 4, 250, 100, 12, 1));
    tower1Upgrades.push_front(Upgrade(700, 1, 3, 100, 10, 8, 1));
    tower1Upgrades.push_front(Upgrade(600, 1.1, 2, 50, 10, 4, 1));
    tower1Upgrades.push_front(Upgrade(500, 1.25, 1, 25, 10, 3, 1));
    tower1Upgrades.push_front(Upgrade(400, 1.5, 0, 10, 10, 3, 1));

    //Machine gun or something
    tower2Upgrades.push_front(Upgrade(500, 0.075, 4, 250, 100, 2, 1));
    tower2Upgrades.push_front(Upgrade(450, 0.1, 3, 100, 10, 2, 1));
    tower2Upgrades.push_front(Upgrade(400, 0.125, 2, 50, 10, 2,1));
    tower2Upgrades.push_front(Upgrade(350, 0.15, 1, 25, 10, 1,1));
    tower2Upgrades.push_front(Upgrade(300, 0.2, 0, 10, 10, 1,1));

    //Sniper or something
    tower3Upgrades.push_front(Upgrade(2000, 1.75, 4, 250, 100, 15, 1));
    tower3Upgrades.push_front(Upgrade(1500, 2, 3, 100, 10, 12, 1));
    tower3Upgrades.push_front(Upgrade(1200, 2.25, 2, 50, 10, 9, 1));
    tower3Upgrades.push_front(Upgrade(800, 2.5, 1, 25, 10, 6, 1));
    tower3Upgrades.push_front(Upgrade(600, 3, 0, 10, 10, 3, 1));

    //Close quarters monster
    tower4Upgrades.push_front(Upgrade(600, 0.7, 4, 250, 100, 14, 0.75));
    tower4Upgrades.push_front(Upgrade(500, 0.75, 3, 100, 10, 12, 0.75));
    tower4Upgrades.push_front(Upgrade(500, 0.8, 2, 50, 10, 10, 0.75));
    tower4Upgrades.push_front(Upgrade(400, 0.9, 1, 25, 10, 8, 0.75));
    tower4Upgrades.push_front(Upgrade(300, 1, 0, 10, 10, 6, 0.75));
}

void TowerManager::createTower(const sf::Vector2f &position,
                               const TowerType &towerType) {
    std::cout << "tower actually placed at :" << position.x << ", " << position.y << std::endl;
    switch (towerType) {
        case TowerType::Tower1:
            towers.emplace_back(resourceManager.GetTexture(ResourceIdentifier::mcleod), position, tower1Upgrades.begin(), tower1Upgrades.end(), towerType);
            break;
        case TowerType::Tower2:
            towers.emplace_back(resourceManager.GetTexture(ResourceIdentifier::mcleod), position, tower2Upgrades.begin(), tower2Upgrades.end(), towerType);
            break;
        case TowerType::Tower3:
            towers.emplace_back(resourceManager.GetTexture(ResourceIdentifier::mcleod), position, tower3Upgrades.begin(), tower3Upgrades.end(), towerType);
            break;
        case TowerType::Tower4:
            towers.emplace_back(resourceManager.GetTexture(ResourceIdentifier::mcleod), position, tower4Upgrades.begin(), tower4Upgrades.end(), towerType);
            break;
        default:
            throw std::runtime_error("Non recognized tower created");
    }

}

void TowerManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (const auto &tower: towers)
        tower.draw(target, states);
    auto trackHitBoxes = map.getTrackHitBoxes();
    auto tempCircle = sf::CircleShape(1);
    //const sf::Vector2f &pos = collidesCircleRectangle(towerSizeCircle, *(++trackHitBoxes.begin()));
    //tempCircle.setPosition(pos.x,pos.y);
    //target.draw(tempCircle);
    //target.draw(towerSizeCircle,states);
}

int TowerManager::getFirstRange(TowerType towerType) const {
    switch (towerType) {
        case TowerType::Tower1:
            return tower1Upgrades.front().range;
        case TowerType::Tower2:
            return tower2Upgrades.front().range;
        case TowerType::Tower3:
            return tower3Upgrades.front().range;
        case TowerType::Tower4:
            return tower4Upgrades.front().range;
        default:
            throw std::runtime_error("Non recognized tower created");
    }
}

bool TowerManager::isTowerPositionValid(float x, float y)  {
    towerSizeCircle.setPosition(x,y);
    auto trackHitBoxes = map.getTrackHitBoxes();
    for(const auto &lineSeg: trackHitBoxes) {
        //To be honest I have no idea how this works in the slightest but it seems to sort of work
        if(collision::areColliding(towerSizeCircle, lineSeg)) {
            return false;
        }
        //if (collidesCircleRectangle(towerSizeCircle, lineSeg)) {
            //return false;
        //}
    }
    for(const auto &tower: towers)
        if(collision::areColliding(tower.getHitBox(), towerSizeCircle))
            return false;
    return true;
}

bool TowerManager::isTowerPositionValid(sf::Vector2f position) {
    return isTowerPositionValid(position.x, position.y);
}