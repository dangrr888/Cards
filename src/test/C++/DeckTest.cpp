#include "gtest/gtest.h"
#include "Card.h"
#include "suits.h"
#include "denomenations.h"
#include "Hand.h"
#include "Deck.h"
#include <array>

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
    const std::array<suit, 2> suits {suit::SPADES, suit::HEARTS};
    const std::array<denom, 3> denom {denom::ACE, denom::FIVE, denom::KING};
    deck d( suits.cbegin()
          , suits.cend()
          , denom.cbegin()
          , denom.cend()
          , deck::Id{42}
      );
  }

  TEST_F(DeckTest, CreateDeckFromCards)
  {
    const std::array<card, 4> cards { card{suit::SPADES, denom::ACE}
                                    , card{suit::SPADES, denom::JACK}
                                    , card{suit::DIAMONDS, denom::NINE}
                                    , card{suit::CLUBS, denom::FOUR}
                                    };

    deck d( cards.cbegin()
          , cards.cend()
          , deck::Id{42}
      );
  }

} // ! namespace testing
