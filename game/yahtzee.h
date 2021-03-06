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
    int rollAll();
    int rollOne(int toRoll);
    int rollMany(int toRoll[5]);
    int assignClass(int scoringClass);



private:
    Die _gameDie = Die(6);
    std::vector<int> _dice;
    int _usedClasses[13] = {0};
    int _score = 0;
    int _round = 0;
    int _rollNum = 0;
};
