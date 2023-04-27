
#include <iostream>
#include "Piece.h"

Piece::Piece(char printChar) : printChar(printChar) {}

void Piece::print() {
    std::cout << printChar;
}

char Piece::getPiece() {
    return printChar;
}