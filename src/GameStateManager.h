//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_GAMESTATEMANAGER_H
#define FIGHTCLUB_GAMESTATEMANAGER_H

enum GameState {
    PreGame = 0,
    Playing = 1,
    Round_Interim = 2,
    Lose = 3,
};

class GameStateManager {
private:
    int health, maxHealth, round, maxRound, money;
    bool paused;
public:
    int getHealth() const;

    void setHealth(int health);

    int getMaxHealth() const;

    void setMaxHealth(int maxHealth);

    int getRound() const;

    void setRound(int round);

    int getMaxRound() const;

    void setMaxRound(int maxRound);

    int getMoney() const;

    void setMoney(int money);

    GameState getGameState() const;

    void setGameState(GameState gameState);

    void start();
    void togglePause();

    bool isPaused();
    GameStateManager(int maxHealth, int maxRound);

private:
    GameState gameState;

};


#endif //FIGHTCLUB_GAMESTATEMANAGER_H
