/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/
TEST(GuesserTest, correct_guess){
	Guesser g("thisisasecret");
	ASSERT_EQ(true, g.match("thisisasecret"));
}

TEST(GuesserTest, incorrect_guess_longer_guess){
	Guesser g("thisisasecret");
	ASSERT_EQ(false, g.match("ThiSisASEcret123456"));
}

TEST(GuesserTest, too_many_guesses){
	Guesser g("thisisasecret");
	bool matched;
	matched = g.match("Thisisasecret");
	matched = g.match("tHisisasecret");
	matched = g.match("thIsisasecret");
	ASSERT_EQ(false, g.match("thisisasecret"));
}

TEST(GuesserTest, secret_too_long){
	Guesser g("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv");
	ASSERT_EQ(false, g.match("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv"));
}

TEST(GuesserTest, three_guesses_left){
	Guesser g("hi");
	bool matched;
	matched = g.match("hi");
	ASSERT_EQ(3, g.remaining());
}

TEST(GuesserTest, two_guesses_left){
	Guesser g("hi");
	bool matched;
	matched = g.match("Hi");
	ASSERT_EQ(2, g.remaining());
}

TEST(GuesserTest, one_guess_left){
	Guesser g("hi");
	bool matched;
	matched = g.match("Hi");
	matched = g.match("hI");
	ASSERT_EQ(1, g.remaining());
}

TEST(GuesserTest, zero_guess_left){
	Guesser g("hi");
	bool matched;
	matched = g.match("Hi");
	matched = g.match("Hi");
	matched = g.match("Hi");
	ASSERT_EQ(0, g.remaining());
}
TEST(GuesserTest, incorrect_guess_shorter_guess){
	Guesser g("hellothere");
	ASSERT_EQ(false, g.match("hi"));
}
