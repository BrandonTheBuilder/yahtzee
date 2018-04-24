#include "yahtzee.h"
#include <algorithm>

int scoreNumber(int die[5], int number) {
    int score = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (die[i] == number)
        {
            score += number;
        }
    }
    if (score >= 63)
    {
        score += 35;
    }
    return score;
}

int scoreXOfAKind(int die[5], int x) {
    int numbers[5] = {0};
    for (int i = 0; i < 5; ++i)
    {
        numbers[die[i]-1] += 1;
    }
    for (int i = 0; i < 5; ++i)
    {
        if(numbers[i] >= x) {
            return sum(die);
        }
    }
    return 0;
}

int scoreFullHouse(int die[5]) {
    int ranks[5] = {0};
    int three_house = 0;
    int two_house = 0;
    for (int i = 0; i < 5; ++i)
    {
        int index = die[i]-1; 
        ranks[index] += 1;
        if(ranks[index] == 2) {
            two_house = 1;
        }
        else if (ranks[index] == 3)
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
    int die_cp[5];
    std::copy(die, die + 5, die_cp);
    std::sort(die_cp, die_cp + 5);
    // Start with the first die in the sorted list
    int previous = die_cp[0];
    // set the count to one
    int count = 1;
    for (int i = 1; i < 5; ++i)
    {
        if (previous + 1 == die_cp[i])
        {
            count += 1;
        }
        else {
            count = 1;
        }
        if (count >= cutoff)
        {
            return 30;
        }
        previous = die_cp[i];
    }
    return 0;
}

int scoreLargeStraight(int die[5]) {
    return 0;
}

int scoreChance(int die[5]) {
    return 0;
}

int scoreYahtzee(int die[5]) {
    return 0;
}

int sum(int die[5]) {
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        sum += die[i];
    }
    return sum;
}