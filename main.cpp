#include <iostream>
#include <ctime>
#include <fstream>
#include "menu/Menu.h"
#include "game/Game.h"

int main() {
    srand(time(nullptr));

    int k;

    // Normal game menu
    do {
        printMainMenu();
        (std::cin >> k);
        if (k == 1) {        //Single Player
            Game *game = new Game(SINGLE_PLAYER);
            int temp;
            while ((temp = game->next()) == 0) {}
            if (temp != 1 && temp != 2) {
                delete game;
                return 1;
            } else {
                game->end(temp);
            }
            delete game;
        } else if (k == 2) {        //Multi Player
            Game *game = new Game(MULTI_PLAYER);
            int temp;
            while ((temp = game->next()) == 0) {}
            if (temp != 1 && temp != 2) {
                delete game;
                return 1;
            } else {
                game->end(temp);
            }
            delete game;
        } else if (k == 3) {        //Read file
            std::string path;
            //Gets file name
            std::cout << "Insert saved game file name:";
            std::cin >> path;
            path.append(".txt");
            std::ifstream file(path);
            //Checks if exists!
            if (file.bad()) {
                std::cout << "Invalid file" << std::endl;
                file.close();
            } else {
                //Print content
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                }
                std::cout << std::endl;
            }
        } else if (k != 0) {
            std::cout << "Invalid input!" << std::endl;
        }
    } while (k != 0 && k != 1 && k != 2);
    return 0;
}
