#include "suits.h"

#include <iostream>

namespace suits
{

  std::ostream& operator<<(std::ostream& os, STANDARD suit)
  {
    switch (suit)
    {
    case STANDARD::HEARTS:
      os << "HEARTS";
      break;
    case STANDARD::DIAMONDS:
      os << "DIAMONDS";
      break;
    case STANDARD::SPADES:
      os << "SPADES";
      break;
    case STANDARD::CLUBS:
      os << "CLUBS";
      break;
    case STANDARD::NONE:
      os << "NONE";
      break;
    default:
      break;
    }

    return os;
  }

} // ! namespace suits
