#include "game/scoring.cpp"
#include <gtest/gtest.h>

TEST(ScoringTest, ScoreXOfAKind) {
    int die[5] = {4, 4, 4, 6, 5};
    int expected = 23;
    ASSERT_EQ(expected, scoreXOfAKind(die, 3));
}

TEST(ScoringTest, ScoringFullHouse) {
    int die[5] = {4, 4, 4, 2, 2};
    int die_no_score[5] = {4, 4, 1, 2, 3};
    ASSERT_EQ(25, scoreFullHouse(die));
    ASSERT_EQ(0, scoreFullHouse(die_no_score));
}

TEST(ScoringTest, ScoringStraight) {
    int smallStraight[5] = {4, 2, 1, 6, 3};
    int straightTwo[5] = {2, 1, 3, 3, 4};
    int largeStraight[5] = {2, 1, 3, 4, 5};
    int die_no_score[5] = {6, 5, 1, 2, 3};
    ASSERT_EQ(30, scoreStraight(straightTwo, 4));
    ASSERT_EQ(30, scoreStraight(smallStraight, 4));
    ASSERT_EQ(0, scoreStraight(smallStraight, 5));
    ASSERT_EQ(30, scoreStraight(largeStraight, 5));
    ASSERT_EQ(30, scoreStraight(largeStraight, 4));
    ASSERT_EQ(0, scoreStraight(die_no_score, 4));
    ASSERT_EQ(0, scoreStraight(die_no_score, 5));
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