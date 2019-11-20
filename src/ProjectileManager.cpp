//
// Created by Bruce on 2019-10-12.
//

#include "ProjectileManager.h"

ProjectileManager::ProjectileManager(){
    std::vector<Projectile> projectiles;
}
void ProjectileManager::update(std::vector<Enemy>& enemies, float delta) {
    for (int i = 0; i < projectiles.size(); i++) {
        projectiles.at(i).update(enemies, delta);
        if (projectiles.at(i).isDeletable() == true) {
            projectiles.erase(projectiles.begin() + i);
        }
    }
}


void ProjectileManager::addProjectile(int speed, int damage, float angle,
        sf::Vector2f position, sf::Texture &texture, sf::FloatRect& bounds){
   Projectile proj = Projectile(speed, damage, angle, position, texture, bounds);
   projectiles.push_back(proj);
}

std::vector<Projectile> ProjectileManager::getProjectiles(){
    return projectiles;
}

void ProjectileManager::draw(sf::RenderTarget &target, sf::RenderStates states) {
    for (int i = 0; i < projectiles.size(); i++)
        projectiles.at(i).draw(target, states);
}

