//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_PROJECTILE_H
#define FIGHTCLUB_PROJECTILE_H


#include <vector>
#include "Enemy.h"

class Projectile: sf::Sprite {
private:
    const sf::Vector2f target;
public:
    explicit Projectile(const sf::Vector2f &target);
    /**
     * Updates the position of a projectile
     * @param delta time since last frame
     */
    void update(long long int delta);


};


#endif //FIGHTCLUB_PROJECTILE_H
