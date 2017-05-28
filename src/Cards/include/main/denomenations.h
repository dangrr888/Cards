#ifndef GUARD_DENOMENATIONS_H_ /// @todo - rename this file and update the header guards
#define GUARD_DENOMENATIONS_H_

#include <iosfwd>

namespace denomenations /// @todo - change this to basic namespace
{

  enum class STANDARD /// @todo - change this to STANDARDDENOMENATION
  {
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    JOKER

  }; // ! enumeration STANDARD

  std::ostream& operator<<(std::ostream& os, STANDARD denom);

} // ! namespace denomenations

#endif // ! denomenations.h
