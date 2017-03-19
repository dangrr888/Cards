#include "gtest/gtest.h"
#include "BlackJackHand.h"
#include "BlackJackCard.h"
#include "suits.h"
#include "denomenations.h"
#include "Error.h"

#include <array>
#include <iostream>
#include <sstream>
#include <string>

namespace testing
{

  using bjsuit = blackjack::BLACKJACKSUIT;
  using bjdenom = blackjack::BLACKJACKDENOMENATION;
  using bjcard = blackjack::BlackJackCard;
  using bjhand = blackjack::BlackJackHand;

  TEST(BlackJackHandTest, CreateHandFromId)
  {
    bjhand h(bjhand::Id{0});
  }

  TEST(BlackJackHandTest, CreateHandFromCards)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);
    const bjcard ace_diamonds(bjsuit::DIAMONDS, bjdenom::ACE);
    const bjcard jack_diamonds(bjsuit::HEARTS, bjdenom::JACK);

    std::array<const bjcard*, 3> v{ &ace_hearts
                                  , &ace_diamonds
                                  , &jack_diamonds
                                  };

    bjhand h(v.cbegin(), v.cend(), bjhand::Id{0});

    std::stringstream ss;
    ss << h;

    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackHand>\n"
                  "\t<BlackJackCard suit=\"HEARTS\", denomenation=\"ACE\">\n"
                  "\t<BlackJackCard suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "\t<BlackJackCard suit=\"HEARTS\", denomenation=\"JACK\">\n"
                  "</BlackJackHand>"
    );
  }

  TEST(BlackJackHandTest, AddCardToHand)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);
    const bjcard ace_diamonds(bjsuit::DIAMONDS, bjdenom::ACE);
    const bjcard jack_diamonds(bjsuit::HEARTS, bjdenom::JACK);

    std::array<const bjcard*, 3> v{ &ace_hearts
                                 , &ace_diamonds
                                 , &jack_diamonds
                                 };

    bjhand h(v.cbegin(), v.cend(), bjhand::Id{0});

    const bjcard queen_diamonds(bjsuit::DIAMONDS, bjdenom::QUEEN);
    h.add_card(&queen_diamonds);

    std::stringstream ss;
    ss << h;

    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackHand>\n"
                  "\t<BlackJackCard suit=\"HEARTS\", denomenation=\"ACE\">\n"
                  "\t<BlackJackCard suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "\t<BlackJackCard suit=\"HEARTS\", denomenation=\"JACK\">\n"
                  "\t<BlackJackCard suit=\"DIAMONDS\", denomenation=\"QUEEN\">\n"
                  "</BlackJackHand>"
    );
  }

  TEST(BlackJackHandTest, AddNullCardToHand)
  {
    bjhand h(bjhand::Id{0});

    h.add_card(nullptr);
    ASSERT_EQ(h.num_cards(), 0);
  }

  TEST(BlackJackHandTest, PlayCardFromEmptyHandAndThrow)
  {
    bjhand h(bjhand::Id{0});

    try
    {
      h.play_card();
      FAIL() << "Expected basic::error::get_card_with_invalid_index to be thrown.";
    }
    catch(basic::error::get_card_with_invalid_index& e)
    {
      ASSERT_EQ(std::string(e.what()), std::string("Attempt to play a card with invalid index: "));
    }
    catch(...)
    {
      FAIL() << "Expected basic::error::get_card_with_invalid_index to be thrown.";
    }
  }

  TEST(BlackJackHandTest, PlayRandomCardFromHand)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);
    const bjcard ace_diamonds(bjsuit::DIAMONDS, bjdenom::ACE);

    std::array<const bjcard*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    bjhand h(v.cbegin(), v.cend(), bjhand::Id{0});

    /// @note - currently we play the first card from the Hand.
    ASSERT_EQ(h.play_card(), &ace_hearts);
  }

  TEST(BlackJackHandTest, PlayCardFromHand)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);
    const bjcard ace_diamonds(bjsuit::DIAMONDS, bjdenom::ACE);

    std::array<const bjcard*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    bjhand h(v.cbegin(), v.cend(), bjhand::Id{0});

    std::stringstream ss;
    ss << h;

    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackHand>\n"
                  "\t<BlackJackCard suit=\"HEARTS\", denomenation=\"ACE\">\n"
                  "\t<BlackJackCard suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "</BlackJackHand>"
    );

    ASSERT_EQ(h.play_card(0), &ace_hearts);

    ss.str("");
    ss << h;
    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackHand>\n"
                  "\t<BlackJackCard suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "</BlackJackHand>"
    );

    ASSERT_EQ(h.play_card(0), &ace_diamonds);

    ss.str("");
    ss << h;
    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackHand>\n"
                  "</BlackJackHand>"
    );
  }

  TEST(BlackJackHandTest, PlayCardFromHandAndThrow)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);

    bjhand h(bjhand::Id{0});
    h.add_card(&ace_hearts);

    ASSERT_THROW( h.play_card(1)
                , basic::error::get_card_with_invalid_index
                );
  }

  TEST(BlackJackHandTest, PeekCardFromEmptyHandAndThrow)
  {
    bjhand h(bjhand::Id{0});

    ASSERT_THROW( h.peek_card()
                , basic::error::get_card_with_invalid_index
    );
  }

  TEST(BlackJackHandTest, PeekRandomCardFromHand)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);
    const bjcard ace_diamonds(bjsuit::DIAMONDS, bjdenom::ACE);

    std::array<const bjcard*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    bjhand h(v.cbegin(), v.cend(), bjhand::Id{0});

    /// @note - currently we play the first card from the Hand.
    ASSERT_EQ(h.peek_card(), &ace_hearts);
  }

  TEST(BlackJackHandTest, PeekCardFromHand)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);
    const bjcard ace_diamonds(bjsuit::DIAMONDS, bjdenom::ACE);

    std::array<const bjcard*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    bjhand h(v.cbegin(), v.cend(), bjhand::Id{0});

    ASSERT_EQ(h.peek_card(1), &ace_diamonds);

    std::stringstream ss;
    ss << h;

    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackHand>\n"
                  "\t<BlackJackCard suit=\"HEARTS\", denomenation=\"ACE\">\n"
                  "\t<BlackJackCard suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "</BlackJackHand>"
    );
  }

  TEST(BlackJackHandTest, PeekCardFromHandAndThrow)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);

    bjhand h(bjhand::Id{0});
    h.add_card(&ace_hearts);

    ASSERT_THROW( h.peek_card(1)
                , basic::error::get_card_with_invalid_index
                );
  }

  TEST(BlackJackHandTest, IterateThroughCards)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);
    const bjcard ace_diamonds(bjsuit::DIAMONDS, bjdenom::ACE);

    std::array<const bjcard*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    bjhand h(v.cbegin(), v.cend(), bjhand::Id{0});

    std::stringstream ss;
    for(auto iter = h.cbegin(); iter != h.cend(); ++iter)
    {
      ss << **iter;
    }

    ASSERT_STREQ( ss.str().c_str()
                , "<BlackJackCard suit=\"HEARTS\", denomenation=\"ACE\">"
                  "<BlackJackCard suit=\"DIAMONDS\", denomenation=\"ACE\">"
    );
  }

  TEST(BlackJackHandTest, NumCards)
  {
    const bjcard ace_hearts(bjsuit::HEARTS, bjdenom::ACE);
    const bjcard ace_diamonds(bjsuit::DIAMONDS, bjdenom::ACE);

    std::array<const bjcard*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    bjhand h(v.cbegin(), v.cend(), bjhand::Id{0});
    ASSERT_EQ(h.num_cards(), 2);
  }

  TEST(BlackJackHandTest, GetId)
  {
    bjhand h(bjhand::Id{42});
    ASSERT_EQ(h.id(), 42);
  }

} // ! namespace testing
