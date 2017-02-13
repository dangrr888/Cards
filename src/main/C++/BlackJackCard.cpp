#include "BlackJackCard.h"
#include <cstdint>

namespace blackjack
{

  bool BlackJackCard::ace() const noexcept
  {
    return this->suit() == BLACKJACKCARD::ACE;
  }

  uint4_t BlackJackCard::min_value() const noexcept
  {
    uint4_t val = 0;
    switch (this->denomenation())
      {
      case BLACKJACKCARD::ACE:
	val = 1;
	break;
      case BLACKJACKCARD::TWO:
	val = 2;
	break;
      case BLACKJACKCARD::THREE:
	val = 3;
	break;
      case BLACKJACKCARD::FOUR:
	val = 4;
	break;
      case BLACKJACKCARD::FIVE:
	val = 5;
	break;
      case BLACKJACKCARD::SIX:
	val = 6;
	break;
      case BLACKJACKCARD::SEVEN:
	val = 7;
	break;
      case BLACKJACKCARD::EIGHT:
	val = 8;
	break;
      case BLACKJACKCARD::NINE:
	val = 9;
	break;
      case BLACKJACKCARD::TEN:
      case BLACKJACKCARD::JACK:
      case BLACKJACKCARD::QUEEN:
      case BLACKJACKCARD::KING:
	val = 10;
	break;
      default:
	break; // @todo - consider thorowing new error here and removing noexcept.
      }

    return val;
  }

  uint4_t BlackJackCard::max_value() const noexcept
  {
    uint4_t val = 0;
    if (this->ace())
    {
      val = 11;
    }
    else
    {
      val = this->min_value();
    }
    return val;
  }

} // ! namespace blackjack
