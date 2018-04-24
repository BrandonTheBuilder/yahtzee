#include <iostream>
#include "die.h"

class Yahtzee {
public:
    Yahtzee();
    ~Yahtzee() {}
    void roll(int diceToRoll[5]);
    void scoreRound(int scoringClass);
    void startGame();
private:
    Die gameDie = Die(6);
    int dice[5];
    int usedClasses[13] = {0};
    int score = 0;
};

int scoreNumber(int die[5], int number);
int scoreXOfAKind(int die[5], int x);
int scoreFullHouse(int die[5]);
int scoreStraight(int die[5], int cutoff);
int scoreChance(int die[5]);
int scoreYahtzee(int die[5]);
int sum(int die[5]);