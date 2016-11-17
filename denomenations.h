#ifndef GUARD_DENOMENATIONS_H_
#define GUARD_DENOMENATIONS_H_

namespace denomenations
{

enum class STANDARD
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
}; // ! enumeration STANDARD

/// @todo - rewrite this in terms of constexpr functions.
std::ostream& operator<<( std::ostream& os
			, STANDARD denom)
{
  switch (denom)
  {
  case example::DENOMENATION::ACE:
    std::cout << "ACE";
    break;
  case example::DENOMENATION::TWO:
    std::cout << "TWO";
    break;
  case example::DENOMENATION::THREE:
    std::cout << "THREE";
    break;
  case example::DENOMENATION::FOUR:
    std::cout << "FOUR";
    break;
  case example::DENOMENATION::FIVE:
    std::cout << "FIVE";
    break;
  case example::DENOMENATION::SIX:
    std::cout << "SIX";
    break;
  case example::DENOMENATION::SEVEN:
    std::cout << "SEVEN";
    break;
  case example::DENOMENATION::EIGHT:
    std::cout << "EIGHT";
    break;
  case example::DENOMENATION::NINE:
    std::cout << "NINE";
    break;
  case example::DENOMENATION::TEN:
    std::cout << "TEN";
    break;
  case example::DENOMENATION::JACK:
    std::cout << "JACK";
    break;
  case example::DENOMENATION::QUEEN:
    std::cout << "QUEEN";
    break;
  case example::DENOMENATION::KING:
    std::cout << "KING";
    break;
  default:
    break;
  }
  
  return os;
}

} // ! namespace denomenations

#endif // ! denomenations.h
