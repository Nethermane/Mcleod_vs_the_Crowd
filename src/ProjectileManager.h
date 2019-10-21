//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_PROJECTILEMANAGER_H
#define FIGHTCLUB_PROJECTILEMANAGER_H

#include "Projectile.h"

class ProjectileManager {
public:
    std::vector<Projectile> projectiles;
    /**
     * Updates the position of all enemies
     * Then checks collision with list of all enemies
     * @param enemies all enemies
     * @param delta time since last frame
     */
    void update(std::vector<Enemy> enemies, float delta);
};


#endif //FIGHTCLUB_PROJECTILEMANAGER_H
