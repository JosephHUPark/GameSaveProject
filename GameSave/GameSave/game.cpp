#include "game.h"

Game::Game(int m) {
    int tm = 60, counter = 0;

    if (m == -1) {
        sql.load_data(m, x, y, tm);
    }
    else {
        for (unsigned int i = 0; i < modes[m].size(); i++) {
            for (unsigned int j = 0; j < modes[m][i].size(); j++) {
                if (modes[m][i][j] == 'X') {
                    y = i, x = j;
                }
            }
        }
    }

    while (true) {
        if (modes[m][y][x] == 'E') {
            std::cout << "You win!" << std::endl;
            Sleep(500);
            break;
        }
        Sleep(10);
        counter++;
        if (counter % 10 == 0) tm--;

        if (tm == 0 || !drawboard(m, tm)) {
            std::cout << "Game over!" << std::endl;
            Sleep(500);
            break;
        }
    }
}

Game::~Game() {
}

bool Game::drawboard(int m, int time) {
    system("cls");

    std::cout << "Use arrow keys to move\nPress 'esc' to leave\nPress '1' to save\n" << std::endl;

    std::cout << "\t\t\t TIME LEFT: " << time << std::endl;

    for (unsigned int i = 0; i < modes[m].size(); i++) {
        for (unsigned int j = 0; j < modes[m][i].size(); j++) {
            if (i == y && j == x)
                std::cout << 'O';
            else
                std::cout << modes[m][i][j];
        }
        std::cout << std::endl;
    }

    if (_kbhit()) {
        switch (_getch()) {
        case 72:
            if (y - 1 >= 0 && modes[m][y - 1][x] != '#')
                y--;
            break;
        case 80:
            if (y + 1 < modes[m].size() && modes[m][y + 1][x] != '#')
                y++;
            break;
        case 75:
            if (x - 1 >= 0 && modes[m][y][x-1] != '#')
                x--;
            break;
        case 77:
            if (x + 1 < modes[m][y].size() && modes[m][y][x + 1] != '#')
                x++;
            break;
        case 27:
            return false;
        case 49:
            sql.save_data(m, x, y, time);
            std::cout << "DATA SAVED!" << std::endl;
            break;
        default:
            break;
        }
    }
    return true;
}