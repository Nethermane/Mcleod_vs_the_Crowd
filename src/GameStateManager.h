//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_GAMESTATEMANAGER_H
#define FIGHTCLUB_GAMESTATEMANAGER_H

///Enum for game state
enum class GameState {
    PreGame = 0,
    Playing = 1,
    Round_Interim = 2,
    Lose = 3,
};

///Class that stores player health, round, and money
class GameStateManager {
private:
    int health, maxHealth, round, maxRound, money;
    bool paused;
    GameState gameState;
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

    ///Set playing true
    void start();

    ///Pauses or un-pauses game state
    void togglePause();

    bool isPaused();

    ///Constructor for new game state manager
    ///@param maxHealth the maximum health of the player
    ///@param maxRound the maximum round for this game instance
    GameStateManager(int maxHealth, int maxRound);

};


#endif //FIGHTCLUB_GAMESTATEMANAGER_H
