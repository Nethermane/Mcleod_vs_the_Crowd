//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_PROJECTILEMANAGER_H
#define FIGHTCLUB_PROJECTILEMANAGER_H

#include "Projectile.h"

class ProjectileManager {
private:
    std::vector<Projectile> projectiles;
public:
    /**
     * Updates the position of all enemies
     * Then checks collision with list of all enemies
     * @param enemies all enemies
     * @param delta time since last frame
     */
    ProjectileManager();
    void update(std::vector<Enemy> &enemies, float delta);
    void addProjectile(int speed, int damage, float angle, sf::Vector2f position, sf::Texture &texture, sf::FloatRect& bounds);
    std::vector<Projectile> getProjectiles();
    void draw(sf::RenderTarget &target, sf::RenderStates states);
};


#endif //FIGHTCLUB_PROJECTILEMANAGER_H
