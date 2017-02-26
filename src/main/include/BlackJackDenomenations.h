#ifndef GUARD_BLACKJACKDENOMENATIONS_H_
#define GUARD_BLACKJACKDENOMENATIONS_H_

#include <iosfwd>

namespace blackjack
{

  enum class BLACKJACKDENOMENATION
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
    KING

  }; // ! enum class BLACKJACKSUIT

  std::ostream& operator<<(std::ostream& os, BLACKJACKDENOMENATION denom);

} // ! namespace blackjack

#endif // ! GUARD_BLACKJACKDENOMENATIONS_H_
