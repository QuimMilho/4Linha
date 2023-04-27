cmake_minimum_required(VERSION 3.20)
project(Miguel)

set(CMAKE_CXX_STANDARD 14)

add_executable(Miguel main.cpp board/Board.cpp board/Board.h pieces/Piece.cpp pieces/Piece.h pieces/PlayerPiece.cpp pieces/PlayerPiece.h pieces/EmptyPiece.cpp pieces/EmptyPiece.h game/Game.cpp game/Game.h menu/Menu.cpp menu/Menu.h)
