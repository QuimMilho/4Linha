
#ifndef MIGUEL_GAME_H
#define MIGUEL_GAME_H

#include "../board/Board.h"

#define SINGLE_PLAYER 0
#define MULTI_PLAYER 1
#define RELOAD 2

#define BIN_SAVE "./stored.bin"

class Game {
private:
    Board *board;
    bool verifyWinner();
    int nPlays;
    int *plays;
    int nextPlay[8];
    void newPlay(int spot);
    char gamemode;
public:
    Game(char gamemode);
    ~Game();
    int next();
    int end(int result);
};

#endif
