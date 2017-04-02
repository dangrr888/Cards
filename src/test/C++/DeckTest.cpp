#include "gtest/gtest.h"
#include "Card.h"
#include "suits.h"
#include "denomenations.h"
#include "Hand.h"
#include "Deck.h"

namespace testing
{

  class DeckTest : public ::testing::Test
  {
  public:
    using suit = suits::STANDARD;
    using denom = denomenations::STANDARD;
    using card = basic::Card<suit, denom>;
    using hand = basic::Hand<card>;
    using deck = basic::Deck<card>;

  protected:
    static void SetUpTestCase();
    static void TearDownTestCase();

    void SetUp();
    void TearDown();

  }; // ! class DeckTest

  void DeckTest::SetUpTestCase()
  {
  }

  void DeckTest::TearDownTestCase()
  {
  }

  void DeckTest::SetUp()
  {
    ::testing::Test::SetUp();
  }

  void DeckTest::TearDown()
  {
    ::testing::Test::TearDown();
  }

  TEST_F(DeckTest, CreateDeckFromSuitsDenomsAndId)
  {
    const std::deque<suit> suits {suit::SPADES, suit::HEARTS};
    const std::deque<denom> denom {denom::ACE, denom::FIVE, denom::KING};
    deck d( suits.cbegin()
          , suits.cend()
          , denom.cbegin()
          , denom.cend()
          , deck::Id{42}
      );
  }


} // ! namespace testing
