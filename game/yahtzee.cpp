#include "yahtzee.h"

void Yahtzee::startGame() {
    std::cout << "Welcome to Yahtzee!!";
    for (int i = 1; i <= 13; ++i)
    {
        std::cout << "Welcome to round " << i << "\n";
        for (int i = 0; i < 3; ++i)
        {
            if (i == 0)
            {
                std::cout << "Time for the first roll \n";
                for (int i = 0; i < 5; ++i)
                {
                    _dice[i] = _gameDie.roll();
                    std::cout << _dice[i] << ", ";
                }

            }
            else if (i == 1)
            {
                std::cout << "\nYou may re-roll one of the die\n";
                int dieToRoll;
                std::cout << "Enter a valid integer [0-4]\n";
                std::cin >> dieToRoll;
                for (int i = 0; i < 5; ++i)
                {
                    if(i == dieToRoll)
                    {
                        _dice[i] = _gameDie.roll();
                    }
                    std::cout << _dice[i] << ", ";
                }
                std::cout << "\n";
            }
            else if (i == 2)
            {
                std::cout << "You may re-roll as many die as you please.\n";
                int diceToRoll[5];
                std::cout << "For the 5 dice enter a 1 to re-roll and a 0 to keep";
                for (int i = 0; i < 5; ++i)
                {
                    std::cin >> diceToRoll[i];
                }
                for (int i = 0; i < 5; ++i)
                {
                    if (diceToRoll[i] == 1)
                    {
                        _dice[i] = _gameDie.roll();
                    }
                    std::cout << _dice[i] << ", ";
                }
                std::cout << "\n";
            }
            int choice;
            std::cout << "Keep this roll, 0 or keep rolling 1 \n";
            std::cin >> choice;
            if(choice == 0) {
                break;
            }
        }
        int roundScored = 0;
        while(roundScored == 0) {
            int scoringClass;
            std::cout << "Assign a scoring class, 0-12\n";
            std::cin >> scoringClass;
            if(_usedClasses[scoringClass] == 0) {
                scoreRound(scoringClass);
                roundScored = 1;
            }
            else {
                std::cout << "You have already used this class\n";
            }
        }
    }
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
    return 1;
}

int Yahtzee::rollOne(int toRoll) {
    return 1;
}

int Yahtzee::rollMany(int toRoll[5]) {
    return 1;
}

int Yahtzee::assignClass(int class) {
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