//
// Created by Bruce on 2019-10-12.
//

#include "Tower.h"
#include "MathHelpers.h"

Tower::Tower(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f &position,
             std::forward_list<Upgrade>::const_iterator nextUpgrade,
             std::forward_list<Upgrade>::const_iterator upgradeEnd) :
        towerPosition(position), nextUpgrade(nextUpgrade), upgradeEnd(upgradeEnd), timeSinceLastAttack(0) {

    ///Sprite handling
    towerSprite.setTexture(*texture);
    towerSprite.setScale(0.6,0.6);
    towerSprite.setOrigin(towerSprite.getLocalBounds().width / 2, towerSprite.getLocalBounds().height / 2);
    towerSprite.setPosition(position);
    upgrade();


}

void Tower::update(float delta, const std::vector<Enemy> &enemies, const std::function<void(Enemy)> &f) {
    if (timeSinceLastAttack > attackDelay) {
        if (!enemies.empty()) {
            Enemy closestEnemy = enemies.front();
            float closestDistance = distBetweenTwoPoints(towerSprite.getPosition(), closestEnemy.sprite.getPosition());
            for (const auto &enemy: enemies) {
                float tempDist = distBetweenTwoPoints(towerSprite.getPosition(), enemy.sprite.getPosition());
                if (tempDist < closestDistance) {
                    closestEnemy = enemy;
                    closestDistance = tempDist;
                }
            }
            if (closestDistance < range) {
                towerSprite.setRotation(
                        angleBetweenTwoPoints(towerSprite.getPosition(), closestEnemy.sprite.getPosition()));
                f(closestEnemy);
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
    nextUpgrade = std::next(nextUpgrade, 1);
}




