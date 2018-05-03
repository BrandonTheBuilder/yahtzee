#include <iostream>
#include "die.h"
#include "scoring.h"

class Yahtzee {
public:
    void scoreRound(int scoringClass);
    void startGame();
private:
    Die gameDie = Die(6);
    int dice[5];
    int usedClasses[13] = {0};
    int score = 0;
};
