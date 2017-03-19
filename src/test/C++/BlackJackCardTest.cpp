// C++
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <cstdint>
#include <utility>
#include <deque>

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

  class BlackJackCardTestWithParameterizedValues
    : public ::testing::TestWithParam<std::pair<bjdenom, std::uint8_t>>
  {
  }; // !  fixture class BlackJackCardTestWithParameterizedValues

  using val_pair = std::pair<bjdenom, std::uint8_t>;
  std::deque<val_pair> vals
  {
    val_pair(bjdenom::TWO,   2),
    val_pair(bjdenom::THREE, 3),
    val_pair(bjdenom::FOUR,  4),
    val_pair(bjdenom::FIVE,  5),
    val_pair(bjdenom::SIX,   6),
    val_pair(bjdenom::SEVEN, 7),
    val_pair(bjdenom::EIGHT, 8),
    val_pair(bjdenom::NINE,  9),
    val_pair(bjdenom::TEN,   10),
    val_pair(bjdenom::JACK,  10),
    val_pair(bjdenom::QUEEN, 10),
    val_pair(bjdenom::KING,  10)
  };

  INSTANTIATE_TEST_CASE_P( BlackJackCardTestWithParameterizedValues
                         , BlackJackCardTestWithParameterizedValues
                         , ::testing::ValuesIn(vals)
                         );

  TEST_P(BlackJackCardTestWithParameterizedValues, GetMinValue)
  {
    const bjcard clubcard(bjsuit::CLUBS, GetParam().first);
    ASSERT_EQ(clubcard.min_value(), GetParam().second);
  }

  TEST_P(BlackJackCardTestWithParameterizedValues, GetMaxValue)
  {
    const bjcard clubcard(bjsuit::CLUBS, GetParam().first);
    ASSERT_EQ(clubcard.max_value(), GetParam().second);
  }

  TEST(BlackJackCardTest, GetAceMinValue)
  {
    const bjcard ace_of_clubs(bjsuit::CLUBS, bjdenom::ACE);
    ASSERT_EQ(ace_of_clubs.min_value(), 1);
  }

  TEST(BlackJackCardTest, GetAceMaxValue)
  {
    const bjcard ace_of_clubs(bjsuit::CLUBS, bjdenom::ACE);
    ASSERT_EQ(ace_of_clubs.max_value(), 11);
  }

} // ! namespace testing
