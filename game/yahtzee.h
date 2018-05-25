#include <iostream>
#include "die.h"
#include "scoring.h"

class Yahtzee {
public:
    void scoreRound(int scoringClass);
    void startGame();
    int gameComplete();
    int getDice(int out[5]);
    int getScore();
    int getRound();
    int getRollNum();


private:
    Die _gameDie = Die(6);
    int _dice[5];
    int _usedClasses[13] = {0};
    int _score = 0;
    int _round = 0;
    int _rollNum = 0;
};
