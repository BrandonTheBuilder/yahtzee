#include "yahtzee.h"
#include <algorithm>
// Util functions
int sum(const std::vector<int>& die) {
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        sum += die[i];
    }
    return sum;
}

//Funtions for scoring yahtzee hand

// Out is an array initialized to zero in which to hold the count
std::vector<int> countDie(const std::vector<int>& die) {
    std::vector<int> out(6, 0);
    for (int i = 0; i < 5; ++i)
    {
        out[die[i]-1] += 1;
    }
    return out;
}

/*
    scores x points for each die showing x pips
*/
int scoreNumber(const std::vector<int>& die, int x) {
    int score = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (die[i] == x)
        {
            score += x;
        }
    }
    return score;
}

/*
    scores the total pips shown on all die if at least
    x are the same rank. 
*/
int scoreXOfAKind(const std::vector<int>& die, int x) {
    std::vector<int> ranks(6, 0);
    ranks = countDie(die);
    for (int i = 0; i < 6; ++i)
    {
        if(ranks[i] >= x) {
            return sum(die);
        }
    }
    return 0;
}

/*
    scores 25 if the roll has 3 dice showing one rank and 
    2 showing another. 
*/
int scoreFullHouse(const std::vector<int>& die) {
    std::vector<int> ranks(6, 0);
    ranks = countDie(die);
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

/*
    If cutoff die show consecutive ranks scores 30 if the cutoff is 
    4 scores 40 if the cutoff is 5. 
*/
int scoreStraight(const std::vector<int>& die, int cutoff) {
    std::vector<int> ranks(6, 0);
    ranks = countDie(die);
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
            return 40 - (5-cutoff) * 10;
        }
    }
    return 0;
}

/*
    scores the sum of all pips shown on die. 
*/
int scoreChance(const std::vector<int>& die) {
    return sum(die);
}

/*
    Scores 50 points if all die show the same rank
*/
int scoreYahtzee(const std::vector<int>& die) {
    std::vector<int> ranks(6, 0);
    ranks = countDie(die);
    for (int i = 0; i < 6; ++i)
     {
         if (ranks[i] >= 5)
         {
             return 50;
         }
     } 
    return 0;
}
