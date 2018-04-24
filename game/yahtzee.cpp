#include "yahtzee.h"

Yahtzee::Yahtzee() { 
}   

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
                    this->dice[i] = this->gameDie.roll();
                    std::cout << this->dice[i] << ", ";
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
                        this->dice[i] = this->gameDie.roll();
                    }
                    std::cout << this->dice[i] << ", ";
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
                        this->dice[i] = this->gameDie.roll();
                    }
                    std::cout << this->dice[i] << ", ";
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
            if(this->usedClasses[scoringClass] == 0) {
                this->scoreRound(scoringClass);
                roundScored = 1;
            }
            else {
                std::cout << "You have already used this class\n";
            }
        }
    }
}

void Yahtzee::roll(int diceToRoll[5]) {

}

void Yahtzee::scoreRound(int scoringClass) {
    this->usedClasses[scoringClass] = 1;
    int roundScore = 0;
    switch(scoringClass) {
        case 0 :
            roundScore += scoreNumber(this->dice, 1);
            break;
        case 1 :
            roundScore += scoreNumber(this->dice, 2);
            break;
        case 2 :
            roundScore += scoreNumber(this->dice, 3);
            break;
        case 3 :
            roundScore += scoreNumber(this->dice, 4);
            break;
        case 4 :
            roundScore += scoreNumber(this->dice, 5);
            break;
        case 5 :
            roundScore += scoreNumber(this->dice, 6);
            break;
        case 6 :
            roundScore += scoreXOfAKind(this->dice, 3);
            break;
        case 7 :
            roundScore += scoreXOfAKind(this->dice, 4);
            break;
        case 8 :
            roundScore += scoreFullHouse(this->dice);
            break;
        case 9 :
            roundScore += scoreStraight(this->dice, 4);
            break; 
        case 10 :
            roundScore += scoreStraight(this->dice, 5);
            break;
        case 11 :
            roundScore += scoreChance(this->dice);
            break;
        case 12 :
            roundScore += scoreYahtzee(this->dice);
            break;
    }
    std::cout << "Initial score: " << this->score << "\n";
    std::cout << "Round score: " << roundScore << "\n";
    this->score += roundScore;
    std::cout << "New score: " << this->score << "\n";
}