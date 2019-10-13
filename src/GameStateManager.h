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
    Pause = 4
};

class GameStateManager {
private:
    int health, maxHealth, round, maxRound, money;
    GameState gameState;

};


#endif //FIGHTCLUB_GAMESTATEMANAGER_H
