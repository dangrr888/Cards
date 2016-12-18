#include "gtest/gtest.h"

class CardTest : public ::testing::Test
{
protected:

  static void SetUpTestCase();
  static void TearDownTestCase();

  void SetUp();
  void TearDown();
};

void CardTest::SetUpTestCase()
{
}

void CardTest::TearDownTestCase()
{
}

void CardTest::SetUp()
{
  ::testing::Test::SetUp();
}

void CardTest::TearDown()
{
  ::testing::Test::TearDown();
}

TEST_F(CardTest, DummyTest)
{
  ASSERT_TRUE(true);
}
