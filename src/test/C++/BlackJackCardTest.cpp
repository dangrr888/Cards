// C++
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <cstdint>
#include <utility>
#include <vector>

// Custom
#include "suits.h"
#include "denomenations.h"
#include "BlackJackCard.h"

// Testing
#include "gtest/gtest.h"

namespace testing
{

  using bjsuit = blackjack::BLACKJACKSUIT;
  using bjdenom = blackjack::BLACKJACKDENOMENATION;
  using bjcard = blackjack::BlackJackCard;

  TEST(BlackJackCardTest, CreateBlackJackCard)
  {
    const bjcard ace_of_spades(bjsuit::SPADES, bjdenom::ACE);
  }

  TEST(BlackJackCardTest, SerializeOutput)
  {
    const bjcard ace_of_spades(bjsuit::SPADES, bjdenom::ACE);
    std::stringstream ss;
    ss << ace_of_spades;
    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackCard suit=\"SPADES\", denomenation=\"ACE\">"
                );
  }

  TEST(BlackJackCardTest, CopyCard)
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

  TEST(BlackJackCardTest, GetSuit)
  {
    const bjcard ace_of_spades(bjsuit::HEARTS, bjdenom::ACE);
    ASSERT_EQ(bjsuit::HEARTS, ace_of_spades.suit());
  }

  TEST(BlackJackCardTest, GetDenomenation)
  {
    const bjcard ace_of_spades(bjsuit::HEARTS, bjdenom::ACE);
    ASSERT_EQ(bjdenom::ACE, ace_of_spades.denomenation());
  }

  TEST(BlackJackCardTest, GetAce)
  {
    const bjcard ace_of_spades(bjsuit::HEARTS, bjdenom::ACE);
    ASSERT_TRUE(ace_of_spades.ace());
  }

  TEST(BlackJackCardTest, GetNotAce)
  {
    const bjcard deuce_of_spades(bjsuit::HEARTS, bjdenom::TWO);
    ASSERT_FALSE(deuce_of_spades.ace());
  }

  class BlackJackCardTestWithParameterizedDenomenations
    : public ::testing::TestWithParam<std::pair<bjdenom, std::uint8_t>>
  {
  }; // !  fixture class BlackJackCardTestWithParameterizedDenomenations

  using min_val_pair = std::pair<bjdenom, std::uint8_t>;
  std::vector<min_val_pair> minvals
  {
    min_val_pair(bjdenom::ACE, 1),
    min_val_pair(bjdenom::TWO, 2),
    min_val_pair(bjdenom::THREE, 3),
    min_val_pair(bjdenom::FOUR, 4)
  };

  TEST_P(BlackJackCardTestWithParameterizedDenomenations, GetMinValue)
  {
    const bjcard clubcard(bjsuit::CLUBS, GetParam().first);
    ASSERT_EQ(clubcard.min_value(), GetParam().second);
  }

  INSTANTIATE_TEST_CASE_P( BlackJackCardTestWithParameterizedDenomenationsInstance
                         , BlackJackCardTestWithParameterizedDenomenations
                         , ::testing::ValuesIn(minvals)
                         );

} // ! namespace testing
