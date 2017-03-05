// C++

// Custom
#include "BlackJackCard.h"
#include "BlackJackHand.h"

// Testing
#include "gtest/gtest.h"

namespace testing
{

  class BlackJackHandTest : public ::testing::Test
  {
  public:
    using bjsuit = blackjack::BLACKJACKSUIT;
    using bjdenom = blackjack::BLACKJACKDENOMENATION;
    using bjcard = blackjack::BlackJackHand;
    using bjhand = blackjack::BlackJackHand;

  protected:
    static void SetUpTestCase();
    static void TearDownTestCase();

    void SetUp();
    void TearDown();
  };

  void BlackJackHandTest::SetUpTestCase()
  {
  }

  void BlackJackHandTest::TearDownTestCase()
  {
  }

  void BlackJackHandTest::SetUp()
  {
    ::testing::Test::SetUp();
  }

  void BlackJackHandTest::TearDown()
  {
    ::testing::Test::TearDown();
  }

  TEST_F(BlackJackHandTest, CreateBlackJackHandFromId)
  {
    bjhand h{bjhand::Id{0}};
  }

} // ! namespace testing
