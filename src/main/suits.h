#ifndef GUARD_SUITS_H_
#define GUARD_SUITS_H_

#include <iostream>

namespace suits
{

enum class STANDARD
{
  HEARTS,
  DIAMONDS,
  SPADES,
  CLUBS,
  NONE
}; // ! enumeration STANDARD

std::ostream& operator<<(std::ostream& os, STANDARD suit)
{
  switch (suit)
  {
  case STANDARD::HEARTS:
    std::cout << "HEARTS";
    break;
  case STANDARD::DIAMONDS:
    std::cout << "DIAMONDS";
    break;
  case STANDARD::SPADES:
    std::cout << "SPADES";
    break;
  case STANDARD::CLUBS:
    std::cout << "CLUBS";
    break;
  case STANDARD::NONE:
    std::cout << "NONE";
    break;
  default:
    break;
  }

  return os;
}

} // ! namespace suits

#endif // ! suits.h
