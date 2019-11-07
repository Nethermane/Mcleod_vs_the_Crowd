//
// Created by Bruce on 2019-11-07.
//

#ifndef FIGHTCLUB_UPGRADE_H
#define FIGHTCLUB_UPGRADE_H


///Class to represent an upgrade that changes a towers stats
class Upgrade {
private:
    friend class Tower;
    friend class TowerManager;

    const int range, attackSpeed, level, upgradeCost, cost;

    explicit Upgrade(const int &range, const int &attackSpeed, const int &level,
                     const int &upgradeCost, const int &cost);

public:
    int getUpgradeCost() const;
};


#endif //FIGHTCLUB_UPGRADE_H
