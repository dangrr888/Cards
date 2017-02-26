#ifndef GUARD_SUITS_H_
#define GUARD_SUITS_H_

#include <iosfwd>

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

  std::ostream& operator<<(std::ostream& os, STANDARD suit);

} // ! namespace suits

#endif // ! suits.h
