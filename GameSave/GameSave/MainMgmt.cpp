#include "MainMgmt.h"

MainMgmt::MainMgmt() {
    system("cls");
    std::cout << "Which mode would you like to play on?\n(0) load game\n(1) easy\n(9) leave" << std::endl;
    int choice = 0;
    std::cin >> choice;
    if (0 <= choice && choice <= 1) {
        
        playgame(choice);
    }
    else if (choice == 9)
    {
        system("cls");
        std::cout << "Goodbye!" << std::endl;
    }
    else
    {
        system("cls");
        std::cout << "That is not a choice!" << std::endl;
        MainMgmt();
    }
}

MainMgmt::~MainMgmt() {};

void MainMgmt::playgame(int choice) {
    Game g = Game(choice - 1);
    MainMgmt();
}