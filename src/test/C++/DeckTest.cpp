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

  TEST_F(DeckTest, NumCards)
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

    ASSERT_EQ(d.num_cards(), 4);
  }

  TEST_F(DeckTest, NumUndealtCards)
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

    ASSERT_EQ(d.num_undealt_cards(), 4);
  }

  TEST_F(DeckTest, NumDealtCards)
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

    ASSERT_EQ(d.num_dealt_cards(), 0);
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

    ASSERT_EQ(d.num_cards(), 4);
    ASSERT_EQ(d.num_dealt_cards(), 0);
    ASSERT_EQ(d.num_undealt_cards(), 4);

    d.add_card( card {suit::HEARTS, denom::QUEEN} );

    ASSERT_EQ(d.num_cards(), 5);
    ASSERT_EQ(d.num_dealt_cards(), 0);
    ASSERT_EQ(d.num_undealt_cards(), 5);
  }

  TEST_F(DeckTest, DealCard)
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

    ASSERT_EQ(d.num_cards(), 4);
    ASSERT_EQ(d.num_dealt_cards(), 0);
    ASSERT_EQ(d.num_undealt_cards(), 4);

    d.add_card( card {suit::HEARTS, denom::QUEEN} );

    ASSERT_EQ(d.num_cards(), 5);
    ASSERT_EQ(d.num_dealt_cards(), 0);
    ASSERT_EQ(d.num_undealt_cards(), 5);

    ASSERT_TRUE(d.deal_card());

    ASSERT_EQ(d.num_cards(), 5);
    ASSERT_EQ(d.num_undealt_cards(), 4);
    ASSERT_EQ(d.num_dealt_cards(), 1);
  }

  TEST_F(DeckTest, GetId)
  {
    const std::array<card, 4> cards { card{suit::SPADES, denom::ACE}
                                    , card{suit::SPADES, denom::JACK}
                                    , card{suit::DIAMONDS, denom::NINE}
                                    , card{suit::CLUBS, denom::FOUR}
                                    };

    deck::Id id{42};
    deck d( cards.cbegin()
          , cards.cend()
          , id
      );

    ASSERT_EQ(d.id(), id);
  }


} // ! namespace testing
