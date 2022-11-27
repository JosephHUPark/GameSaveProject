#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "mysql.h"

class Game {

    std::vector<std::vector<std::string>> modes = { {
        "#############",
        "#     #    ##",
        "# ### # ## ##",
        "# # # # #  ##",
        "X #     # # E",
        "##  ##### # #",
        "#  #      # #",
        "# ## ###### #",
        "#  #        #",
        "#############"
    } };

    bool drawboard(int m, int time);
    
    mysql sql = mysql();
    int x, y;

public:
    Game(int m);
    ~Game();


};