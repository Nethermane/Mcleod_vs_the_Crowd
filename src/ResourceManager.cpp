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

ResourceManager::ResourceManager() = default;
