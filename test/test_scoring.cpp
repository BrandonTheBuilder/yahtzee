#include "../game/scoring.h"
#include <gtest/gtest.h>

TEST(ScoreXOfAKind, one) {
    std::vector<int> die = {1, 2, 1, 1, 1};
    int expected = 6;
    ASSERT_EQ(expected, scoreXOfAKind(die, 4));
}

TEST(ScoreXOfAKind, two) {
    std::vector<int> die = {4, 4, 4, 6, 5};
    int expected = 23;
    ASSERT_EQ(expected, scoreXOfAKind(die, 3));
}

TEST(ScoreXOfAKind, three) {
    std::vector<int> die = {3, 3, 3, 1, 2};
    int expected = 12;
    ASSERT_EQ(expected, scoreXOfAKind(die, 3));
}

TEST(ScoreXOfAKind, sixes) {
    std::vector<int> die = {6, 6, 6, 6, 5};
    int expected = 29;
    ASSERT_EQ(expected, scoreXOfAKind(die, 4));
}

TEST(ScoringScoringFullHouse, One) {
    std::vector<int> die = {3, 3, 3, 1, 1};
    ASSERT_EQ(25, scoreFullHouse(die));
}

TEST(ScoringScoringFullHouse, Two) {
    std::vector<int> die = {4, 4, 4, 6, 6};
    ASSERT_EQ(25, scoreFullHouse(die));
}

TEST(ScoringScoringFullHouse, Three) {
    std::vector<int> die = {4, 5, 4, 6, 6};
    ASSERT_EQ(0, scoreFullHouse(die));
}

TEST(ScoringScoringFullHouse, Four) {
    std::vector<int> die = {2, 2, 2, 1, 6};
    ASSERT_EQ(0, scoreFullHouse(die));
}

TEST(ScoringScoringFullHouse, Five) {
    std::vector<int> die = {1, 2, 1, 2, 1};
    ASSERT_EQ(25, scoreFullHouse(die));
}

TEST(TestStraight, One) {
    std::vector<int> die = {4, 2, 1, 6, 3};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(0, scoreStraight(die, 5));
}

TEST(TestStraight, Two) {
    std::vector<int> die = {1, 3, 6, 5, 4};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(0, scoreStraight(die, 5));
}

TEST(TestStraight, Three) {
    std::vector<int> die = {1, 3, 2, 5, 4};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(40, scoreStraight(die, 5));
}

TEST(TestStraight, Four) {
    std::vector<int> die = {2, 1, 3, 3, 4};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(0, scoreStraight(die, 5));
}

TEST(TestStraight, Five) {
    std::vector<int> die = {4, 2, 4, 5, 3};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(0, scoreStraight(die, 5));
}

TEST(TestStraight, Six) {
    std::vector<int> die = {4, 2, 5, 6, 3};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(40, scoreStraight(die, 5));
}

TEST(TestChance, One) {
    std::vector<int> die = {2, 2, 1, 3, 4};
    ASSERT_EQ(12, scoreChance(die));
}

TEST(TestScoreYahtzee, One) {
    std::vector<int> die = {1, 1, 1, 1, 1};
    ASSERT_EQ(50, scoreYahtzee(die));
}

TEST(TestScoreYahtzee, Two) {
    std::vector<int> die = {2, 2, 1, 2, 2};
    ASSERT_EQ(0, scoreYahtzee(die));
}

TEST(TestScoreYahtzee, Three) {
    std::vector<int> die = {6, 6, 6, 6, 6};
    ASSERT_EQ(50, scoreYahtzee(die));
}

TEST(TestScoreYahtzee, Four) {
    std::vector<int> die = {1, 3, 2, 4, 6};
    ASSERT_EQ(0, scoreYahtzee(die));
}

TEST(TestSort, One) {
    std::vector<int> die = {2, 1, 3, 3, 4};
    int expected[6] = {1, 1, 2, 1, 0, 0};
    int sorted[6] = {0};
    countDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

TEST(TestSort, Two) {
    std::vector<int> die = {6, 5, 1, 2, 3};
    int expected[6] = {1, 1, 1, 0, 1, 1};
    int sorted[6] = {0};
    countDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

TEST(TestSort, Three) {
    std::vector<int> die = {4, 2, 1, 6, 3};
    int expected[6] = {1, 1, 1, 1, 0, 1};
    int sorted[6] = {0};
    countDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

TEST(TestSort, Four) {
    std::vector<int> die = {6, 5, 1, 2, 2};
    int expected[6] = {1, 2, 0, 0, 1, 1};
    int sorted[6] = {0};
    countDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

TEST(TestSort, scoreNumber) {
    std::vector<int> die = {2, 3, 2, 2, 2};
    int expected = 8;
    EXPECT_EQ(scoreNumber(die, 2), expected);    
}

TEST(TestSort, Five) {
    std::vector<int> die = {5, 4, 3, 2, 1};
    int expected[6] = {1, 1, 1, 1, 1, 0};
    int sorted[6] = {0};
    countDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}
