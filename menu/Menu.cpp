#include "Menu.h"
#include <iostream>

void printMainMenu() {
    std::cout << "Please choose one" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cout << "1 - Single Player" << std::endl;
    std::cout << "2 - Multi Player" << std::endl;
    std::cout << "3 - See old game" << std::endl;
}

void printSaveMenu() {
    std::cout << "Dou you want to save the game?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
}