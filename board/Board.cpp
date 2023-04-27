
#include <iostream>
#include "Board.h"
#include "../pieces/EmptyPiece.h"
#include "../pieces/PlayerPiece.h"

Board::Board(int columns, int row) : columns(columns), row(row) {
    emptyPiece = new EmptyPiece();
    playerAPiece = new PlayerPiece('X');
    playerBPiece = new PlayerPiece('O');
    //Allocates the board
    board = new EmptyPiece[columns * row];
}

Board::~Board() {
    //Deallocate the board
    delete [] board;
    //Deallocate pieces
    delete emptyPiece;
    delete playerAPiece;
    delete playerBPiece;
}

void Board::print() {
    int i, h;
    //Prints first line
    for (i = 0; i < columns + 2; i++) {
        std::cout << (char) 219;
    }
    //Prints the board
    std::cout << std::endl;
    for (i = 0; i < row; i++) {
        std::cout << (char) 219;
        for (h = 0; h < columns; h++) {
            board[i * columns + h].print();
        }
        std::cout << (char) 219 << std::endl;
    }
    std::cout << (char) 219;
    //Print the middle line
    for (i = 0; i < columns; i++) {
        std::cout << (char) 178;
    }
    std::cout << (char) 219 << std::endl << (char) 219;
    //Print numbers
    for (i = 0; i < columns; i++) {
        std::cout << i + 1;
    }
    std::cout << (char) 219 << std::endl;
    //Print bottom line
    for (i = 0; i < columns + 2; i++) {
        std::cout << (char) 219;
    }
    std::cout << std::endl;
}

void Board::changePiece(int x, int y, char player) {
    if (player == 'A') {
        board[(x - 1) * row + (y - 1)] = *playerAPiece;
    } else {
        board[(x - 1) * row + (y - 1)] = *playerBPiece;
    }
}

char Board::getPiece(int x, int y) {
    return board[(y - 1) * row + (x - 1)].getPiece();
}