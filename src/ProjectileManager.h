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
    void update(float delta, std::vector<Enemy> &enemies);
    void addProjectile(float speed, int damage, float angle, sf::Vector2f position, const std::shared_ptr<sf::Texture> &texture, const sf::FloatRect& bounds);
    std::vector<Projectile> getProjectiles();
    void draw(sf::RenderTarget &target, sf::RenderStates states);
};


#endif //FIGHTCLUB_PROJECTILEMANAGER_H
