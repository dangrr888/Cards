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
  CLUBS
}; // ! enumeration STANDARD

/// @todo - rewrite this in terms of constexpr functions.
std::ostream& operator<<(std::ostream& os, STANDARD suit)
{
  switch (suit)
  {
  case suits::SUIT::HEARTS:
    std::cout << "HEARTS";
    break;
  case suits::SUIT::DIAMONDS:
    std::cout << "DIAMONDS";
    break;
  case suits::SUIT::SPADES:
    std::cout << "SPADES";
    break;
  case suits::SUIT::CLUBS:
    std::cout << "CLUBS";
    break;
  default:
    break;
  }

  return os;
}

} // ! namespace suits

#endif // ! suits.h
