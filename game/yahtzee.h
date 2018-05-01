#include <iostream>
#include "die.h"

class Yahtzee {
public:
    void roll(int diceToRoll[5]);
    void scoreRound(int scoringClass);
    void startGame();
private:
    Die gameDie = Die(6);
    int dice[5];
    int usedClasses[13] = {0};
    int score = 0;
};
