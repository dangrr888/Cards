// C++
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>

// Custom
#include "suits.h"
#include "denomenations.h"
#include "BlackJackCard.h"

// Testing
#include "gtest/gtest.h"

namespace testing
{

  class BlackJackCardTest : public ::testing::Test
  {
  public:
    using bjsuit = blackjack::BLACKJACKSUIT;
    using bjdenom = blackjack::BLACKJACKDENOMENATION;
    using bjcard = blackjack::BlackJackCard;

  protected:
    static void SetUpTestCase();
    static void TearDownTestCase();

    void SetUp();
    void TearDown();
  };

  void BlackJackCardTest::SetUpTestCase()
  {
  }

  void BlackJackCardTest::TearDownTestCase()
  {
  }

  void BlackJackCardTest::SetUp()
  {
    ::testing::Test::SetUp();
  }

  void BlackJackCardTest::TearDown()
  {
    ::testing::Test::TearDown();
  }

  TEST_F(BlackJackCardTest, CreateBlackJackCard)
  {
    const bjcard ace_of_spades(bjsuit::SPADES, bjdenom::ACE);
  }

  TEST_F(BlackJackCardTest, SerializeOutput)
  {
    const bjcard ace_of_spades(bjsuit::SPADES, bjdenom::ACE);
    std::stringstream ss;
    ss << ace_of_spades;
    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackCard suit=\"SPADES\", denomenation=\"ACE\">"
                );
  }

  TEST_F(BlackJackCardTest, CopyCard)
  {
    const bjcard ace_of_spades(bjsuit::SPADES, bjdenom::ACE);
    const bjcard ace_of_spades_copy(ace_of_spades);
    std::stringstream ss;
    ss << ace_of_spades_copy;
    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackCard suit=\"SPADES\", denomenation=\"ACE\">"
                );
    ASSERT_EQ(bjsuit::SPADES, ace_of_spades_copy.suit());
    ASSERT_EQ(bjdenom::ACE, ace_of_spades_copy.denomenation());
  }

  TEST_F(BlackJackCardTest, GetSuit)
  {
    const bjcard ace_of_spades(bjsuit::HEARTS, bjdenom::ACE);
    ASSERT_EQ(bjsuit::HEARTS, ace_of_spades.suit());
  }

  TEST_F(BlackJackCardTest, GetDenomenation)
  {
    const bjcard ace_of_spades(bjsuit::HEARTS, bjdenom::ACE);
    ASSERT_EQ(bjdenom::ACE, ace_of_spades.denomenation());
  }

} // ! namespace testing
