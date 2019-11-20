//
// Created by Bruce on 2019-10-12.
//

#include "GameStateManager.h"

int GameStateManager::getHealth() const {
    return health;
}

void GameStateManager::setHealth(int health) {
    GameStateManager::health = health;
}

int GameStateManager::getMaxHealth() const {
    return maxHealth;
}

void GameStateManager::setMaxHealth(int maxHealth) {
    GameStateManager::maxHealth = maxHealth;
}

int GameStateManager::getRound() const {
    return round;
}

void GameStateManager::setRound(int round) {
    GameStateManager::round = round;
}

int GameStateManager::getMaxRound() const {
    return maxRound;
}

void GameStateManager::setMaxRound(int maxRound) {
    GameStateManager::maxRound = maxRound;
}

int GameStateManager::getMoney() const {
    return money;
}

void GameStateManager::setMoney(int money) {
    GameStateManager::money = money;
}

GameState GameStateManager::getGameState() const {
    return gameState;
}

void GameStateManager::setGameState(GameState gameState) {
    GameStateManager::gameState = gameState;
}

void GameStateManager::togglePause() {
    paused = !paused;
}

void GameStateManager::start() {
    gameState = GameState::Playing;
}

bool GameStateManager::isPaused() {
    return paused;
}

GameStateManager::GameStateManager(const int maxHealth, const int maxRound) : health(maxHealth), maxHealth(maxHealth),
                                                                              round(1), maxRound(maxRound), money(0),
                                                                              gameState(GameState::PreGame), paused(false) {}