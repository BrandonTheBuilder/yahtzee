#include "../game/yahtzee.h"
#include <gtest/gtest.h>

TEST(TestYahtzee, instantiation) {
	Yahtzee game = Yahtzee();
}

TEST(TestGameComplete, notComplete) {
	Yahtzee game = Yahtzee();
	game.startGame();
}

TEST(TestRollALl, firstAction) {
	Yahtzee game = Yahtzee();
    ASSERT_TRUE(0 == game.rollAll());
    ASSERT_FALSE(0 == game.rollAll());
}

TEST(TestRollOne, rollOne) {
	Yahtzee game = Yahtzee();
	int toRoll = 1;
	int dice[5];
	int result[5];
	// First try and roll one during the first round
	ASSERT_FALSE(0 == game.rollOne(toRoll));
	// Then roll all die to move to second round
	ASSERT_TRUE(0 == game.rollAll());
	// Store the values of the die for asserting
	game.getDice(dice);
	// Roll a single die
	ASSERT_TRUE(0 == game.rollOne(toRoll));
	// Get the resulting values
	game.getDice(result);
	for (int i = 0; i < 5; ++i)
	{
		if(i != toRoll) {
			// For every die not rolled verify it is unchanged
			ASSERT_EQ(dice[i], result[i]);
		}
	}
}

TEST(TestRollMany, many) {
	Yahtzee game = Yahtzee();
	int toRoll[5] = {0, 1, 1, 0, 0};
	ASSERT_FALSE(0 == game.rollMany(toRoll));
	ASSERT_TRUE(0 == game.rollAll());
	ASSERT_TRUE(0 == game.rollOne(2));
	int dice[5];
	game.getDice(dice);
	ASSERT_TRUE(0 == game.rollMany(toRoll));
	int result[5];
	game.getDice(result);
	for (int i = 0; i < 5; ++i)
	{
		if(toRoll[i] != 1) {
			ASSERT_EQ(dice[i], result[i]);
		}
	}
}
