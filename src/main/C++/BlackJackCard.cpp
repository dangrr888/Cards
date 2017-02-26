#include "BlackJackCard.h"
#include "BlackJackDenomenations.h"

#include <cstdint>

namespace blackjack
{

  bool BlackJackCard::ace() const noexcept
  {
    return this->denomenation() == BLACKJACKDENOMENATION::ACE;
  }

  uint8_t BlackJackCard::min_value() const noexcept
  {
    uint8_t val = 0;
    switch (this->denomenation())
      {
      case BLACKJACKDENOMENATION::ACE:
	val = 1;
	break;
      case BLACKJACKDENOMENATION::TWO:
	val = 2;
	break;
      case BLACKJACKDENOMENATION::THREE:
	val = 3;
	break;
      case BLACKJACKDENOMENATION::FOUR:
	val = 4;
	break;
      case BLACKJACKDENOMENATION::FIVE:
	val = 5;
	break;
      case BLACKJACKDENOMENATION::SIX:
	val = 6;
	break;
      case BLACKJACKDENOMENATION::SEVEN:
	val = 7;
	break;
      case BLACKJACKDENOMENATION::EIGHT:
	val = 8;
	break;
      case BLACKJACKDENOMENATION::NINE:
	val = 9;
	break;
      case BLACKJACKDENOMENATION::TEN:
      case BLACKJACKDENOMENATION::JACK:
      case BLACKJACKDENOMENATION::QUEEN:
      case BLACKJACKDENOMENATION::KING:
	val = 10;
	break;
      default:
	break; // @todo - consider thorowing new error here and removing noexcept.
      }

    return val;
  }

  uint8_t BlackJackCard::max_value() const noexcept
  {
    uint8_t val = 0;
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
