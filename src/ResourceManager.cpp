//
// Created by Bruce on 2019-11-04.
//

#include <iostream>
#include "ResourceManager.h"

std::shared_ptr<sf::Texture> ResourceManager::LoadTexture(ResourceIdentifier id, const std::string &file) {
    std::shared_ptr<sf::Texture> tex = std::make_shared<sf::Texture>();
    (*tex).loadFromFile(file);
    m_Textures.emplace(id, tex);
    return tex;
}

std::shared_ptr<sf::Texture> ResourceManager::GetTexture(ResourceIdentifier id) const {
    return (*m_Textures.find(id)).second;
}

std::shared_ptr<sf::Font> ResourceManager::LoadFont(ResourceIdentifier id, const std::string &file) {
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    (*font).loadFromFile(file);
    m_Fonts.emplace(id, font);
    return font;
}

std::shared_ptr<sf::Font> ResourceManager::GetFont(ResourceIdentifier id) const {
    return (*m_Fonts.find(id)).second;
}

ResourceManager::ResourceManager() {
    LoadTexture(ResourceIdentifier::enemy_1, "../img/enemy_1.png");
    LoadTexture(ResourceIdentifier::enemy_2, "../img/enemy_2.png");
    LoadTexture(ResourceIdentifier::enemy_3, "../img/enemy_3.png");
    LoadTexture(ResourceIdentifier::enemy_4, "../img/enemy_4.png");
    LoadTexture(ResourceIdentifier::enemy_5, "../img/enemy_5.png");
    LoadTexture(ResourceIdentifier::HealthA, "../img/Health_A.png");
    LoadTexture(ResourceIdentifier::HealthB, "../img/Health_B.png");
    LoadTexture(ResourceIdentifier::HealthC, "../img/Health_C.png");
    LoadTexture(ResourceIdentifier::HealthF, "../img/Health_F.png");
    LoadTexture(ResourceIdentifier::sound, "../img/sound.png");
    LoadTexture(ResourceIdentifier::mute, "../img/mute.png");
    LoadTexture(ResourceIdentifier::pause, "../img/pause.png");
    LoadTexture(ResourceIdentifier::options, "../img/gear.png");
    LoadTexture(ResourceIdentifier::pointer, "../img/pointer.png");
    LoadFont(ResourceIdentifier::apex, "../font/ApexMk2-Regular.otf");

    LoadTexture(ResourceIdentifier::a1, "../img/A-1.png");
    LoadTexture(ResourceIdentifier::a2, "../img/A-2.png");
    LoadTexture(ResourceIdentifier::a3, "../img/A-3.png");
    LoadTexture(ResourceIdentifier::b1, "../img/B-1.png");
    LoadTexture(ResourceIdentifier::b2, "../img/B-2.png");
    LoadTexture(ResourceIdentifier::b3, "../img/B-3.png");
    LoadTexture(ResourceIdentifier::c1, "../img/C-1.png");
    LoadTexture(ResourceIdentifier::c2, "../img/C-2.png");
    LoadTexture(ResourceIdentifier::c3, "../img/C-3.png");
    LoadTexture(ResourceIdentifier::d4, "../img/D-4.png");
    LoadTexture(ResourceIdentifier::mcleod1, "../img/mcleod1.png");
    LoadTexture(ResourceIdentifier::mcleod2, "../img/mcleod2.png");
    LoadTexture(ResourceIdentifier::mcleod3, "../img/mcleod3.png");
    LoadTexture(ResourceIdentifier::mcleod4, "../img/mcleod4.png");
    LoadTexture(ResourceIdentifier::track, "../img/track.png");
    LoadTexture(ResourceIdentifier::projectile, "../img/Projectile.png");
}
