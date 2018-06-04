#include "yahtzee.h"

void Yahtzee::startGame() {
    std::cout << "Welcome to Yahtzee!!";
}

int Yahtzee::gameComplete() {
    if (_round == 12)
    {
        return 1;
    }
    return 0;
}

int Yahtzee::getDice(int out[5]) {
    for (int i = 0; i < 5; ++i)
    {
        out[i] = _dice[i];
    }
    return 0;
}

int Yahtzee::getScore() {
    return _score;
}

int Yahtzee::getRound() {
    return _round;
}

int Yahtzee::getRollNum() {
    return _rollNum;
}

int Yahtzee::rollAll() {
    // First roll
    if (_rollNum == 0 )
    {
        _rollNum += 1;
    }
    else {
        return 1;
    }
    for (int i = 0; i < 5; ++i)
    {
        _dice[i] = _gameDie.roll();
    }
    return 0;
}

int Yahtzee::rollOne(int toRoll) {
    // "\nYou may re-roll one of the die\n";
    if(_rollNum == 1) {
        _rollNum += 1;
    }
    else {
        return 1;
    }
    for (int i = 0; i < 5; ++i)
    {
        if(i == toRoll)
        {
            _dice[i] = _gameDie.roll();
        }
    }
    return 0;
}

int Yahtzee::rollMany(int toRoll[5]) {
    if (_rollNum == 2) {
        _rollNum += 1;
    }
    else {
        return 1;
    }
    // "For the 5 dice enter a 1 to re-roll and a 0 to keep";
    for (int i = 0; i < 5; ++i)
    {
        if (toRoll[i] == 1)
        {
            _dice[i] = _gameDie.roll();
        }
    }
    return 0;
}

int Yahtzee::assignClass(int scoringClass) {
    if(_usedClasses[scoringClass] == 0) {
        if (_rollNum == 3 && _round < 12)
        {
            //Reset the roll and increment the round
            _rollNum = 0;
            _round += 1;
            scoreRound(scoringClass);
            return 0;
        }
    }
    return 1;
}

void Yahtzee::scoreRound(int scoringClass) {
    _usedClasses[scoringClass] = 1;
    int roundScore = 0;
    switch(scoringClass) {
        case 0 :
            roundScore += scoreNumber(_dice, 1);
            break;
        case 1 :
            roundScore += scoreNumber(_dice, 2);
            break;
        case 2 :
            roundScore += scoreNumber(_dice, 3);
            break;
        case 3 :
            roundScore += scoreNumber(_dice, 4);
            break;
        case 4 :
            roundScore += scoreNumber(_dice, 5);
            break;
        case 5 :
            roundScore += scoreNumber(_dice, 6);
            break;
        case 6 :
            roundScore += scoreXOfAKind(_dice, 3);
            break;
        case 7 :
            roundScore += scoreXOfAKind(_dice, 4);
            break;
        case 8 :
            roundScore += scoreFullHouse(_dice);
            break;
        case 9 :
            roundScore += scoreStraight(_dice, 4);
            break;
        case 10 :
            roundScore += scoreStraight(_dice, 5);
            break;
        case 11 :
            roundScore += scoreChance(_dice);
            break;
        case 12 :
            roundScore += scoreYahtzee(_dice);
            break;
    }
    std::cout << "Initial score: " << _score << "\n";
    std::cout << "Round score: " << roundScore << "\n";
    _score += roundScore;
    std::cout << "New score: " << _score << "\n";
}