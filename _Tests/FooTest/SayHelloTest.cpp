#include <sayHello/sayHello.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace ::testing;

TEST(ATestThatTests, abs)
{
  EXPECT_EQ(1, abs( -1 ));
  EXPECT_EQ(1, abs( 1 ));
}

TEST(ATestThatTests, SomethingFails)
{
	EXPECT_TRUE(false);
}

TEST(ATestThatTests, ThatMatchersWork)
{
	EXPECT_THAT( "AString", Eq("AString")) << "see the matcher work";
}