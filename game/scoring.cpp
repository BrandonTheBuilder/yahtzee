#include "yahtzee.h"
#include <algorithm>
// Util functions
int sum(int die[5]) {
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        sum += die[i];
    }
    return sum;
}

// Out is an array initialized to zero in which to hold the count
int sortDie(int die[5], int out[6]) {
    for (int i = 0; i < 5; ++i)
    {
        out[die[i]-1] += 1;
    }
    return 0;
}

// Scoring functions
int scoreNumber(int die[5], int number) {
    int score = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (die[i] == number)
        {
            score += number;
        }
    }
    return score;
}

int scoreXOfAKind(int die[5], int x) {
    int ranks[6] = {0};
    sortDie(die, ranks);
    for (int i = 0; i < 6; ++i)
    {
        if(ranks[i] >= x) {
            return sum(die);
        }
    }
    return 0;
}

int scoreFullHouse(int die[5]) {
    int ranks[6] = {0};
    sortDie(die, ranks);
    int three_house = 0;
    int two_house = 0;
    for (int i = 0; i < 6; ++i)
    {
        if(ranks[i] == 2) {
            two_house = 1;
        }
        else if (ranks[i] == 3)
        {
            three_house = 1;
        }

    }
    if ((two_house == 1) & (three_house == 1))
    {
        return 25;
    }
    return 0;
}

int scoreStraight(int die[5], int cutoff) {
    int ranks[6] = {0};
    sortDie(die, ranks);
    int count = 0;
    // Container sort the whole array
    for (int i = 0; i < 6; ++i)
    {
        //If it contains at least one of the value increment the count
        if(ranks[i] >= 1) {
            count += 1;
        }
        else {
            // If it does not contain a value reset the count
            count = 0;
        }
        if(count >= cutoff) {
            return 30;
        }
    }
    return 0;
}

int scoreChance(int die[5]) {
    return sum(die);
}

int scoreYahtzee(int die[5]) {
    int ranks[6] = {0};
    sortDie(die, ranks);
    for (int i = 0; i < 6; ++i)
     {
         if (ranks[i] >= 5)
         {
             return 50;
         }
     } 
    return 0;
}
