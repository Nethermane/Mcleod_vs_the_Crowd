//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include "ProjectileManager.h"

ProjectileManager::ProjectileManager(){
    std::vector<Projectile> projectiles;
}
void ProjectileManager::update(float delta, std::vector<Enemy>& enemies) {
    auto projectile = projectiles.begin();

    while (projectile != projectiles.end()) {
        (*projectile).update(delta, enemies);
        if ((*projectile).isDeletable())
            projectile = projectiles.erase(projectile);
        else
            ++projectile;
    }
}


void ProjectileManager::addProjectile(float speed, int damage, float angle,
        sf::Vector2f position, const std::shared_ptr<sf::Texture> &texture, const sf::FloatRect& bounds){
   Projectile proj = Projectile(speed, damage, angle, position, texture, bounds);
   projectiles.push_back(proj);
}

std::vector<Projectile> ProjectileManager::getProjectiles(){
    return projectiles;
}

void ProjectileManager::draw(sf::RenderTarget &target, sf::RenderStates states) {
    for (auto &projectile : projectiles)
        projectile.draw(target, states);
}

