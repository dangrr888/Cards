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
  KING,
  JOKER  
}; // ! enumeration STANDARD

std::ostream& operator<<(std::ostream& os, STANDARD denom)
{
  switch (denom)
  {
  case STANDARD::ACE:
    std::cout << "ACE";
    break;
  case STANDARD::TWO:
    std::cout << "TWO";
    break;
  case STANDARD::THREE:
    std::cout << "THREE";
    break;
  case STANDARD::FOUR:
    std::cout << "FOUR";
    break;
  case STANDARD::FIVE:
    std::cout << "FIVE";
    break;
  case STANDARD::SIX:
    std::cout << "SIX";
    break;
  case STANDARD::SEVEN:
    std::cout << "SEVEN";
    break;
  case STANDARD::EIGHT:
    std::cout << "EIGHT";
    break;
  case STANDARD::NINE:
    std::cout << "NINE";
    break;
  case STANDARD::TEN:
    std::cout << "TEN";
    break;
  case STANDARD::JACK:
    std::cout << "JACK";
    break;
  case STANDARD::QUEEN:
    std::cout << "QUEEN";
    break;
  case STANDARD::KING:
    std::cout << "KING";
    break;
  case STANDARD::JOKER:
    std::cout << "JOKER";
    break;
  default:
    break;
  }
  
  return os;
}

} // ! namespace denomenations

#endif // ! denomenations.h
