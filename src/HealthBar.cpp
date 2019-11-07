//
// Created by Bruce on 2019-11-04.
//

#include "HealthBar.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

int HealthBar::getHealth() const {
    return health;
}

HealthBar::HealthBar(const int healthMax, std::vector<std::shared_ptr<sf::Texture>> &textures) : textures(textures),
                                                                                                 health(healthMax),
                                                                                                 max(healthMax),
                                                                                                 sections(
                                                                                                         static_cast<int>(textures.size())),
                                                                                                 oldSection(100) {
    updateGraphic();
}

void HealthBar::updateGraphic() {
    int pcnt = health * 100 / max;
    int sectionAmount = 100 / sections;
    int currSection = oldSection;
    for (int i = sections - 1; i >= 0; i--) {
        if (pcnt > i * sectionAmount) {
            currSection = i;
            break;
        }
    }
    if (currSection != oldSection) {
        sprite.setTexture(*(textures.at(static_cast<unsigned long long int>(currSection))));
        sprite.setScale(0.2, 0.2);
        sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    }
    oldSection = currSection;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
void HealthBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}
#pragma clang diagnostic pop

void HealthBar::hit(int damage) {
    health -= damage;
    updateGraphic();
}


void HealthBar::update(const sf::Sprite &toFollow) {
    sprite.setPosition(toFollow.getPosition().x - sprite.getGlobalBounds().width/2, toFollow.getPosition().y - toFollow.getGlobalBounds().height / 2 -
                                                 sprite.getGlobalBounds().height);
}

int HealthBar::getMaxHealth() const {
    return max;
}
