#include <vector>
// Util function
int sum(const std::vector<int>& die);
std::vector<int> countDie(const std::vector<int>& die);
// Scoring funtions
int scoreNumber(const std::vector<int>& die, int number);
int scoreXOfAKind(const std::vector<int>& die, int x);
int scoreFullHouse(const std::vector<int>& die);
int scoreStraight(const std::vector<int>& die, int cutoff);
int scoreChance(const std::vector<int>& die);
int scoreYahtzee(const std::vector<int>& die);
