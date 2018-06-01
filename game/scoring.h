// Util function
int sum(int die[5]);
void sortDie(int die[5], int out[6]);
// Scoring funtions
int scoreNumber(int die[5], int number);
int scoreXOfAKind(int die[5], int x);
int scoreFullHouse(int die[5]);
int scoreStraight(int die[5], int cutoff);
int scoreChance(int die[5]);
int scoreYahtzee(int die[5]);
