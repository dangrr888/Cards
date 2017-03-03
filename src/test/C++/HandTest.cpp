#include "gtest/gtest.h"
#include "Hand.h"
#include "suits.h"
#include "denomenations.h"
#include "Error.h"

#include <array>
#include <iostream>
#include <sstream>
#include <string>

namespace testing
{

  class HandTest : public ::testing::Test
  {
  public:
    using suit = suits::STANDARD;
    using denom = denomenations::STANDARD;
    using card = basic::Card<suit, denom>;
    using hand = basic::Hand<card>;

  protected:
    static void SetUpTestCase();
    static void TearDownTestCase();

    void SetUp();
    void TearDown();

  }; // ! HandTest

  void HandTest::SetUpTestCase()
  {
  }

  void HandTest::TearDownTestCase()
  {
  }

  void HandTest::SetUp()
  {
    ::testing::Test::SetUp();
  }

  void HandTest::TearDown()
  {
    ::testing::Test::TearDown();
  }

  TEST_F(HandTest, CreateHandFromId)
  {
    hand h(hand::Id{0});
  }

  TEST_F(HandTest, CreateHandFromCards)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);
    const card ace_diamonds(suit::DIAMONDS, denom::ACE);
    const card jack_diamonds(suit::HEARTS, denom::JACK);
    const card misterjay(suit::NONE, denom::JOKER);

    std::array<const card*, 4> v{ &ace_hearts
                                , &ace_diamonds
                                , &jack_diamonds
                                , &misterjay
                                };

    hand h(v.cbegin(), v.cend(), hand::Id{0});

    std::stringstream ss;
    ss << h;

    ASSERT_STREQ( ss.str().c_str()
                , "<Hand>\n"
                  "\t<Card suit=\"HEARTS\", denomenation=\"ACE\">\n"
                  "\t<Card suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "\t<Card suit=\"HEARTS\", denomenation=\"JACK\">\n"
                  "\t<Card suit=\"NONE\", denomenation=\"JOKER\">\n"
                  "</Hand>"
    );
  }

  TEST_F(HandTest, AddCardToHand)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);
    const card ace_diamonds(suit::DIAMONDS, denom::ACE);
    const card jack_diamonds(suit::HEARTS, denom::JACK);
    const card misterjay(suit::NONE, denom::JOKER);

    std::array<const card*, 4> v{ &ace_hearts
                                , &ace_diamonds
                                , &jack_diamonds
                                , &misterjay
                                };

    hand h(v.cbegin(), v.cend(), hand::Id{0});

    const card queen_diamonds(suit::DIAMONDS, denom::QUEEN);
    h.add_card(&queen_diamonds);

    std::stringstream ss;
    ss << h;

    ASSERT_STREQ( ss.str().c_str()
                , "<Hand>\n"
                  "\t<Card suit=\"HEARTS\", denomenation=\"ACE\">\n"
                  "\t<Card suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "\t<Card suit=\"HEARTS\", denomenation=\"JACK\">\n"
                  "\t<Card suit=\"NONE\", denomenation=\"JOKER\">\n"
                  "\t<Card suit=\"DIAMONDS\", denomenation=\"QUEEN\">\n"
                  "</Hand>"
    );
  }

  TEST_F(HandTest, AddNullCardToHand)
  {
    hand h(hand::Id{0});

    h.add_card(nullptr);
    ASSERT_EQ(h.num_cards(), 0);
  }

  TEST_F(HandTest, PlayCardFromEmptyHandAndThrow)
  {
    hand h(hand::Id{0});

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

  TEST_F(HandTest, PlayRandomCardFromHand)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);
    const card ace_diamonds(suit::DIAMONDS, denom::ACE);

    std::array<const card*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    hand h(v.cbegin(), v.cend(), hand::Id{0});

    /// @note - currently we play the first card from the Hand.
    ASSERT_EQ(h.play_card(), &ace_hearts);
  }

  TEST_F(HandTest, PlayCardFromHand)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);
    const card ace_diamonds(suit::DIAMONDS, denom::ACE);

    std::array<const card*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    hand h(v.cbegin(), v.cend(), hand::Id{0});

    std::stringstream ss;
    ss << h;

    ASSERT_STREQ( ss.str().c_str()
                , "<Hand>\n"
                  "\t<Card suit=\"HEARTS\", denomenation=\"ACE\">\n"
                  "\t<Card suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "</Hand>"
    );

    ASSERT_EQ(h.play_card(0), &ace_hearts);

    ss.str("");
    ss << h;
    ASSERT_STREQ( ss.str().c_str()
                , "<Hand>\n"
                  "\t<Card suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "</Hand>"
    );

    ASSERT_EQ(h.play_card(0), &ace_diamonds);

    ss.str("");
    ss << h;
    ASSERT_STREQ( ss.str().c_str()
                , "<Hand>\n"
                  "</Hand>"
    );
  }

  TEST_F(HandTest, PlayCardFromHandAndThrow)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);

    hand h(hand::Id{0});
    h.add_card(&ace_hearts);

    ASSERT_THROW( h.play_card(1)
                , basic::error::get_card_with_invalid_index
                );
  }

  TEST_F(HandTest, PeekCardFromEmptyHandAndThrow)
  {
    hand h(hand::Id{0});

    ASSERT_THROW( h.peek_card()
                , basic::error::get_card_with_invalid_index
    );
  }

  TEST_F(HandTest, PeekRandomCardFromHand)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);
    const card ace_diamonds(suit::DIAMONDS, denom::ACE);

    std::array<const card*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    hand h(v.cbegin(), v.cend(), hand::Id{0});

    /// @note - currently we play the first card from the Hand.
    ASSERT_EQ(h.peek_card(), &ace_hearts);
  }

  TEST_F(HandTest, PeekCardFromHand)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);
    const card ace_diamonds(suit::DIAMONDS, denom::ACE);

    std::array<const card*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    hand h(v.cbegin(), v.cend(), hand::Id{0});

    ASSERT_EQ(h.peek_card(1), &ace_diamonds);

    std::stringstream ss;
    ss << h;

    ASSERT_STREQ( ss.str().c_str()
                , "<Hand>\n"
                  "\t<Card suit=\"HEARTS\", denomenation=\"ACE\">\n"
                  "\t<Card suit=\"DIAMONDS\", denomenation=\"ACE\">\n"
                  "</Hand>"
    );
  }

  TEST_F(HandTest, PeekCardFromHandAndThrow)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);

    hand h(hand::Id{0});
    h.add_card(&ace_hearts);

    ASSERT_THROW( h.peek_card(1)
                , basic::error::get_card_with_invalid_index
                );
  }

  TEST_F(HandTest, IterateThroughCards)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);
    const card ace_diamonds(suit::DIAMONDS, denom::ACE);

    std::array<const card*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    hand h(v.cbegin(), v.cend(), hand::Id{0});

    std::stringstream ss;
    for(auto iter = h.cbegin(); iter != h.cend(); ++iter)
    {
      ss << **iter;
    }

    ASSERT_STREQ( ss.str().c_str()
                , "<Card suit=\"HEARTS\", denomenation=\"ACE\">"
                  "<Card suit=\"DIAMONDS\", denomenation=\"ACE\">"
    );
  }

  TEST_F(HandTest, NumCards)
  {
    const card ace_hearts(suit::HEARTS, denom::ACE);
    const card ace_diamonds(suit::DIAMONDS, denom::ACE);

    std::array<const card*, 2> v{ &ace_hearts
                                , &ace_diamonds
                                };

    hand h(v.cbegin(), v.cend(), hand::Id{0});
    ASSERT_EQ(h.num_cards(), 2);
  }

  TEST_F(HandTest, GetId)
  {
    hand h(hand::Id{42});
    ASSERT_EQ(h.id(), 42);
  }

} // ! namespace testing
