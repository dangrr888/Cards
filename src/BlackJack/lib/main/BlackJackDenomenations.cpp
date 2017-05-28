#include "BlackJackDenomenations.h"

#include <iostream>

namespace blackjack
{

  std::ostream& operator<<(std::ostream& os, BLACKJACKDENOMENATION denom)
  {
    switch (denom)
    {
    case BLACKJACKDENOMENATION::ACE:
      os << "ACE";
      break;
    case BLACKJACKDENOMENATION::TWO:
      os << "TWO";
      break;
    case BLACKJACKDENOMENATION::THREE:
      os << "THREE";
      break;
    case BLACKJACKDENOMENATION::FOUR:
      os << "FOUR";
      break;
    case BLACKJACKDENOMENATION::FIVE:
      os << "FIVE";
      break;
    case BLACKJACKDENOMENATION::SIX:
      os << "SIX";
      break;
    case BLACKJACKDENOMENATION::SEVEN:
      os << "SEVEN";
      break;
    case BLACKJACKDENOMENATION::EIGHT:
      os << "EIGHT";
      break;
    case BLACKJACKDENOMENATION::NINE:
      os << "NINE";
      break;
    case BLACKJACKDENOMENATION::TEN:
      os << "TEN";
      break;
    case BLACKJACKDENOMENATION::JACK:
      os << "JACK";
      break;
    case BLACKJACKDENOMENATION::QUEEN:
      os << "QUEEN";
      break;
    case BLACKJACKDENOMENATION::KING:
      os << "KING";
      break;
    default:
      break;
    }

    return os;
  }

} // ! namespace blackjack
