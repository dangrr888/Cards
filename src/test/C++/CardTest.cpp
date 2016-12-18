// C++
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>

// Custom
#include "suits.h"
#include "denomenations.h"
#include "Card.h"

// Testing
#include "gtest/gtest.h"

namespace testing
{

  class CardTest : public ::testing::Test
  {
  public:
    using suit = suits::STANDARD;
    using denom = denomenations::STANDARD;
    using card = basic::Card<suit, denom>;
    
  protected:
    static void SetUpTestCase();
    static void TearDownTestCase();

    void SetUp();
    void TearDown();
  };

  void CardTest::SetUpTestCase()
  {
  }

  void CardTest::TearDownTestCase()
  {
  }

  void CardTest::SetUp()
  {
    ::testing::Test::SetUp();
  }

  void CardTest::TearDown()
  {
    ::testing::Test::TearDown();
  }

  TEST_F(CardTest, CreateCard)
  {
    const card ace_of_spades(suit::SPADES, denom::ACE);
  }

  TEST_F(CardTest, SerializeOutput)
  {
    const card ace_of_spades(suit::SPADES, denom::ACE);
    std::stringstream ss;
    ss << ace_of_spades;
    ASSERT_STREQ( ss.str().c_str()
                , "<Card suit=\"SPADES\", denomenation=\"ACE\">"
                );
  }

  TEST_F(CardTest, CopyCard)
  {
    const card ace_of_spades(suit::SPADES, denom::ACE);
    const card ace_of_spades_copy(ace_of_spades);
    std::stringstream ss;
    ss << ace_of_spades_copy;
    ASSERT_STREQ( ss.str().c_str()
                , "<Card suit=\"SPADES\", denomenation=\"ACE\">"
                );
    ASSERT_EQ(suit::SPADES, ace_of_spades_copy.suit());
    ASSERT_EQ(denom::ACE, ace_of_spades_copy.denomenation());
  }

  TEST_F(CardTest, GetSuit)
  {
    const card ace_of_spades(suit::HEARTS, denom::ACE);
    ASSERT_EQ(suit::HEARTS, ace_of_spades.suit());
  }

  TEST_F(CardTest, GetDenomenation)
  {
    const card ace_of_spades(suit::HEARTS, denom::ACE);
    ASSERT_EQ(denom::ACE, ace_of_spades.denomenation());
  }

} // ! namespace testing
