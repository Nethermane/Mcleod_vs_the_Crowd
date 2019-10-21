//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWERMANAGER_H
#define FIGHTCLUB_TOWERMANAGER_H

#include "Map.h"

/**
 * This class stores all towers and manages the creation of projectiles.
 */
class TowerManager {
private:
    const Map &map;
public:
    explicit TowerManager(const Map &map);
    void update(float delta);
};


#endif //FIGHTCLUB_TOWERMANAGER_H
