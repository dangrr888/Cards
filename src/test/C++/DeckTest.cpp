#include "gtest/gtest.h"
#include "Card.h"
#include "suits.h"
#include "denomenations.h"
#include "Hand.h"
#include "Deck.h"
#include <array>
#include <iostream>

namespace testing
{

  class DeckTest : public ::testing::Test
  {
  public:
    /// @todo - put these in a header file and lose the test fixture.
    using suit = suits::STANDARD;
    using denom = denomenations::STANDARD;
    using card = basic::Card<suit, denom>;
    using hand = basic::Hand<card>;
    using deck = basic::Deck<card>;

  }; // ! class DeckTest

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

  TEST_F(DeckTest, AddCard)
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

    d.add_card( card {suit::HEARTS, denom::QUEEN} );

    std::stringstream ss;
    ss << d;

    ASSERT_STREQ( ss.str().c_str()
                , "<Deck>\n"
                  "\t<Card suit=\"HEARTS\", denomenation=\"QUEEN\">\n"
                  "\t<Card suit=\"CLUBS\", denomenation=\"FOUR\">\n"
                  "\t<Card suit=\"DIAMONDS\", denomenation=\"NINE\">\n"
                  "\t<Card suit=\"SPADES\", denomenation=\"JACK\">\n"
                  "\t<Card suit=\"SPADES\", denomenation=\"ACE\">\n"
                  "</Deck>"
      );
  }

} // ! namespace testing
