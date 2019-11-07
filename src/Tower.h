//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWER_H
#define FIGHTCLUB_TOWER_H


#include <SFML/Graphics/Sprite.hpp>
#include <forward_list>

class Tower;

class Upgrade {
private:
    friend class UpgradeManager;

    const int range, attackSpeed, level, upgradeCost, cost;

    explicit Upgrade(const int &range, const int &attackSpeed, const int &level,
                     const int &upgradeCost, const int &cost);

    void apply(Tower &tower) const;

public:
    int getUpgradeCost() const;
};

class Tower : sf::Sprite {
public:
    bool canUpgrade() const;

    int getUpgradeCost() const;

    std::forward_list<Upgrade>::const_iterator getUpgrade();

private:
    int range, attackSpeed, rotation, lastAttack, cost, level;
    long long int timeSinceLastAttack;

    friend class Upgrade;

    std::forward_list<Upgrade>::const_iterator nextUpgrade;
    std::forward_list<Upgrade>::const_iterator upgradeEnd;
};


#endif //FIGHTCLUB_TOWER_H
