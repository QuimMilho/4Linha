
#include <iostream>
#include <fstream>
#include "Game.h"
#include "../menu/Menu.h"

Game::Game(char gamemode) : gamemode(gamemode) {
    //Creates the board
    board = new Board(8, 8);
    nPlays = 0;
    int i;
    for (i = 0; i < 8; i++) {
        nextPlay[i] = 8;
    }
}

Game::~Game() {
    delete board;
    delete plays;
}

//Next play
int Game::next() {
    int k;
    do {
        if (gamemode == SINGLE_PLAYER) {        //SINGLE PLAYER
            //If user turn (The user goes always first)
            if (nPlays % 2 == 0) {
                board->print();
                std::cout << "Select where you wanna play:";
                std::cin >> k;
                if (!k) {
                    std::cout << "Invalid input!" << std::endl;
                    return -1;
                }
            //If is AI turn
            } else {
                int available[8], i, temp = 0;
                //Get where it can play
                for (i = 0; i < 8; i++) {
                    available[i] = nextPlay[i] == 0 ? 0 : 1;
                    //Number of options
                    temp++;
                }
                // Generates the random play
                int play = rand() % (temp + 1);
                for (i = 0; i < 8; i++) {
                    if (available[i]) {
                        play--;
                    }
                    if (play == 0) {
                        k = i + 1;
                        break;
                    }
                }
            }
        } else {        //MULTI PLAYER
            board->print();
            std::cout << "Player " << (char) ('A' + (nPlays % 2)) << " select where you wanna play:";
            std::cin >> k;
            if (!k) {
                std::cout << "Invalid input!" << std::endl;
                return -1;
            }
        }
        if (k < 1 || k > 8) {
            std::cout << "Invalid input!" << std::endl;
            continue;
        } else {
            if (nextPlay[k - 1] != 0) {
                newPlay(k);
                nextPlay[k - 1]--;
            } else {
                std::cout << "Invalid placement!" << std::endl;
                k = -1;
            }
        }
    } while (k < 1 || k > 8);
    return verifyWinner() ? 1 : nPlays == 64 ? 2 : 0;
}

bool Game::verifyWinner() {
    int i, h;
    for (i = 1; i <= 5; i++) {
        for (h = 1; h <= 8; h++) {
            //Check horizontal lines
            char start = board->getPiece(h, i);
            if (start != ' ') {
                if (start == board->getPiece(h, i + 1) && start == board->getPiece(h, i + 2) && start == board->getPiece(h, i + 3))
                    return true;
            }
            //Check vertical lines
            char start2 = board->getPiece(i, h);
            if (start2 != ' ') {
                if (start2 == board->getPiece(i + 1, h) && start2 == board->getPiece(i + 2, h) && start2 == board->getPiece(i + 3, h))
                    return true;
            }
        }
    }
    return false;
}

//Prints the result and asks if user wants to save the game
int Game::end(int result) {
    //Result
    board->print();
    if (result == 2) {
        std::cout << "It was a Tie!" << std::endl;
    } else {
        if (gamemode == MULTI_PLAYER) {
            std::cout << "Player " << (char) ('A' + ((nPlays - 1) % 2)) << " won!" << std::endl;
        } else {
            if ((nPlays - 1) % 2 == 0) {
                std::cout << "The player won!" << std::endl;
            } else {
                std::cout << "The AI won!" << std::endl;
            }
        }
    }

    int k, i;

    //Save game
    do {
        printSaveMenu();
        std::cin >> k;
        if (k == 1) {        //Save file
            std::cout << "Insert the file name (no spaces): " << std::endl;
            std::string path;
            std::cin >> path;
            path.append(".txt");
            std::ofstream file(path);
            //Saves every play
            for (i = 0; i < nPlays; i++) {
                if (gamemode == SINGLE_PLAYER) {
                    if (i % 2 == 0) {
                        file << "The player chose row number " << plays[i] << std::endl;
                    } else {
                        file << "The AI chose row number " << plays[i] << std::endl;
                    }
                } else {
                    file << "Player " << (char) ('A' + (i % 2)) << " chose row number " << plays[i] << std::endl;
                }
            }
            //Saves the final result
            if (result == 2) {
                file << "It was a Tie!";
            } else {
                if (gamemode == SINGLE_PLAYER) {
                    if ((nPlays - 1) % 2 == 0)
                        file << "Player won!" << std::endl;
                    else
                        file << "AI won!" << std::endl;
                } else {
                    file << "Player " << (char) ('A' + ((nPlays - 1) % 2)) << " won!" << std::endl;
                }
            }
        } else if (k != 2) {
            std::cout << "Invalid input!" << std::endl;
        }
    } while (k != 1 && k != 2);
    return 0;
}

//Registers every play
void Game::newPlay(int spot) {
    nPlays++;
    int *temp = new int[nPlays], i;
    for (i = 0; i < nPlays - 1; i++) {
        temp[i] = plays[i];
    }
    temp[nPlays - 1] = spot;
    delete [] plays;
    plays = temp;
    board->changePiece(nextPlay[spot - 1], spot, (char) ('A' + ((nPlays - 1)) % 2));
}