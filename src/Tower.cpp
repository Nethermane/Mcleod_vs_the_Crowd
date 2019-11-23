//
// Created by Bruce on 2019-10-12.
//

#include "Tower.h"
#include "MathHelpers.h"

Tower::Tower(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f &position,
             std::forward_list<Upgrade>::const_iterator nextUpgrade,
             std::forward_list<Upgrade>::const_iterator upgradeEnd, const TowerType &towerType) :
        towerPosition(position), nextUpgrade(nextUpgrade), upgradeEnd(upgradeEnd), timeSinceLastAttack(0),
        towerType(towerType) {


    ///Sprite handling
    towerSprite.setTexture(*texture);
    towerSprite.setScale(constants::towerSizeMod, constants::towerSizeMod);
    towerSprite.setOrigin(towerSprite.getLocalBounds().width / 2, towerSprite.getLocalBounds().height / 2);
    towerSprite.setPosition(position);
    hitBox = sf::CircleShape(towerSprite.getGlobalBounds().width / 2);
    hitBox.setOrigin(hitBox.getRadius(), hitBox.getRadius());
    hitBox.setPosition(towerSprite.getPosition());
    upgrade();


}

void Tower::update(float delta, const std::vector<Enemy> &enemies, const std::function<void(Tower, Enemy, float)> &f) {
    if (timeSinceLastAttack > attackDelay) {
        if (!enemies.empty()) {
            Enemy toShoot = enemies.front();
            float closestDistance = distBetweenTwoPoints(towerSprite.getPosition(), toShoot.sprite.getPosition());
            for (const auto &enemy: enemies) {
                float tempDist = distBetweenTwoPoints(towerSprite.getPosition(), enemy.sprite.getPosition());
                if (((enemy.getTotalMoveTime() > toShoot.getTotalMoveTime() || closestDistance > range) &&
                     tempDist < range)) {
                    toShoot = enemy;
                    closestDistance = tempDist;
                }

            }
            if (closestDistance < range) {
                auto expectedTravelTime = distBetweenTwoPoints(toShoot.sprite.getPosition(), towerSprite.getPosition())/projectileSpeed;
                auto target = sf::Vector2f(toShoot.sprite.getPosition().x + toShoot.getXangle() * toShoot.getSpeed()*expectedTravelTime,
                                           toShoot.sprite.getPosition().y + toShoot.getYangle() * toShoot.getSpeed()*expectedTravelTime);
                auto angle = angleBetweenTwoPoints(towerSprite.getPosition(), target);
                towerSprite.setRotation(angle);
                f(*this, toShoot, angle);
                timeSinceLastAttack -= attackDelay;
            }
        }
    } else {
        timeSinceLastAttack += delta;
    }
}

void Tower::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(towerSprite, states);
}

TowerType Tower::getTowerType() const {
    return this->type;
}

sf::Vector2f Tower::getPosition() const {
    return towerPosition;
}

int Tower::getUpgradeCost() const {
    return (*nextUpgrade).upgradeCost;
}


bool Tower::canUpgrade() const {
    return nextUpgrade != upgradeEnd;
}


void Tower::upgrade() {
    auto upgrade = *nextUpgrade;
    range = upgrade.range;
    attackDelay = upgrade.attackSpeed;
    level = upgrade.level;
    cost = upgrade.cost;
    damage = upgrade.damage;
    projectileSpeed = constants::projectileSpeed * upgrade.projectileSpeedMod;
    nextUpgrade = std::next(nextUpgrade, 1);
}

int Tower::getDamage() const {
    return damage;
}

float Tower::getProjectileSpeed() const {
    return projectileSpeed;
}

sf::CircleShape Tower::getHitBox() const {
    return hitBox;
}

float Tower::getRange() const {
    return range;
}

float Tower::getNextRange() const {
    if(canUpgrade())
        return (*nextUpgrade).range;
    return range;
}




