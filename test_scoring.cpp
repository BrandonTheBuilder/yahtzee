#include "game/scoring.cpp"
#include <gtest/gtest.h>

TEST(ScoringTest, ScoreXOfAKind) {
    int die[5] = {4, 4, 4, 6, 5};
    int expected = 23;
    ASSERT_EQ(expected, scoreXOfAKind(die, 3));
}

TEST(ScoringScoringFullHouse, One) {
    int die[5] = {3, 3, 3, 1, 1};
    ASSERT_EQ(25, scoreFullHouse(die));
}

TEST(ScoringScoringFullHouse, Two) {
    int die[5] = {4, 4, 4, 6, 6};
    ASSERT_EQ(25, scoreFullHouse(die));
}

TEST(ScoringScoringFullHouse, Three) {
    int die[5] = {4, 5, 4, 6, 6};
    ASSERT_EQ(0, scoreFullHouse(die));
}

TEST(ScoringScoringFullHouse, Four) {
    int die[5] = {2, 2, 2, 1, 6};
    ASSERT_EQ(0, scoreFullHouse(die));
}

TEST(ScoringScoringFullHouse, Five) {
    int die[5] = {1, 2, 1, 2, 1};
    ASSERT_EQ(25, scoreFullHouse(die));
}

TEST(TestStraight, TestStraightOne) {
    int die[5] = {4, 2, 1, 6, 3};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(0, scoreStraight(die, 5));
}

TEST(TestStraight, TestStraightTwo) {
    int die[5] = {1, 3, 6, 5, 4};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(0, scoreStraight(die, 5));
}

TEST(TestStraight, TestStraightThree) {
    int die[5] = {1, 3, 2, 5, 4};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(30, scoreStraight(die, 5));
}

TEST(TestStraight, TestStraightFour) {
    int die[5] = {2, 1, 3, 3, 4};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(0, scoreStraight(die, 5));
}

TEST(TestStraight, TestStraightFive) {
    int die[5] = {4, 2, 4, 5, 3};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(0, scoreStraight(die, 5));
}

TEST(TestStraight, TestStraightSix) {
    int die[5] = {4, 2, 5, 6, 3};
    ASSERT_EQ(30, scoreStraight(die, 4));
    ASSERT_EQ(30, scoreStraight(die, 5));
}

TEST(TestChance, One) {
    int die[5] = {2, 2, 1, 3, 4};
    ASSERT_EQ(12, scoreChance(die));
}

TEST(TestScoreYahtzee, One) {
    int die[5] = {1, 1, 1, 1, 1};
    ASSERT_EQ(50, scoreYahtzee(die));
}

TEST(TestScoreYahtzee, Two) {
    int die[5] = {2, 2, 1, 2, 2};
    ASSERT_EQ(0, scoreYahtzee(die));
}

TEST(TestScoreYahtzee, Three) {
    int die[5] = {6, 6, 6, 6, 6};
    ASSERT_EQ(50, scoreYahtzee(die));
}

TEST(TestScoreYahtzee, Four) {
    int die[5] = {1, 3, 2, 4, 6};
    ASSERT_EQ(0, scoreYahtzee(die));
}

TEST(TestSort, TestSortOne) {
    int die[5] = {2, 1, 3, 3, 4};
    int expected[6] = {1, 1, 2, 1, 0, 0};
    int sorted[6] = {0};
    sortDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

TEST(TestSort, TestSortTwo) {
    int die[5] = {6, 5, 1, 2, 3};
    int expected[6] = {1, 1, 1, 0, 1, 1};
    int sorted[6] = {0};
    sortDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

TEST(TestSort, TestSortThree) {
    int die[5] = {4, 2, 1, 6, 3};
    int expected[6] = {1, 1, 1, 1, 0, 1};
    int sorted[6] = {0};
    sortDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

TEST(TestSort, TestSortFour) {
    int die[5] = {6, 5, 1, 2, 2};
    int expected[6] = {1, 2, 0, 0, 1, 1};
    int sorted[6] = {0};
    sortDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

TEST(TestSort, TestSortFive) {
    int die[5] = {5, 4, 3, 2, 1};
    int expected[6] = {1, 1, 1, 1, 1, 0};
    int sorted[6] = {0};
    sortDie(die, sorted);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(sorted[i], expected[i]) << "Vectors differ at index " << i;
    }
}

int test_main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}