#include "gtest/gtest.h"
#include "Card.h"
#include "suits.h"
#include "denomenations.h"
#include "Hand.h"

namespace testing
{

  class DeckTest : public ::testing::Test
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

  }


} // ! namespace testing
