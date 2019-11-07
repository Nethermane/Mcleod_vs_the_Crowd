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
        LoadTexture(ResourceIdentifier::mcleod, "../img/McLeod.png");
        LoadTexture(ResourceIdentifier::sound, "../img/sound.png");
        LoadTexture(ResourceIdentifier::mute, "../img/mute.png");
        LoadTexture(ResourceIdentifier::pause, "../img/pause.png");
        LoadTexture(ResourceIdentifier::options, "../img/gear.png");
        LoadTexture(ResourceIdentifier::pointer, "../img/pointer.png");
        LoadFont(ResourceIdentifier::apex, "../font/ApexMk2-Regular.otf");
    
}
