
#ifndef MIGUEL_BOARD_H
#define MIGUEL_BOARD_H

#include "../pieces/Piece.h"

class Board {
private:
    Piece *board;
    int columns, row;
    Piece *playerAPiece;
    Piece *playerBPiece;
    Piece *emptyPiece;
public:
    Board(int columns, int row);
    ~Board();

    void print();
    void changePiece(int x, int y, char player);

    char getPiece(int x, int y);
};

#endif