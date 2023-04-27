
#ifndef MIGUEL_PIECE_H
#define MIGUEL_PIECE_H

class Piece {
private:
    char printChar;
protected:
    Piece(char printChar);
public:
    void print();
    char getPiece();
};

#endif
