#include <iostream>
#include "game/yahtzee.h"

int main()
{
    // Seed the random number generator
    srand (time(NULL));
    // test();
    Yahtzee game = Yahtzee();
    game.startGame();
}

