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
    os << "ACE";
    break;
  case STANDARD::TWO:
    os << "TWO";
    break;
  case STANDARD::THREE:
    os << "THREE";
    break;
  case STANDARD::FOUR:
    os << "FOUR";
    break;
  case STANDARD::FIVE:
    os << "FIVE";
    break;
  case STANDARD::SIX:
    os << "SIX";
    break;
  case STANDARD::SEVEN:
    os << "SEVEN";
    break;
  case STANDARD::EIGHT:
    os << "EIGHT";
    break;
  case STANDARD::NINE:
    os << "NINE";
    break;
  case STANDARD::TEN:
    os << "TEN";
    break;
  case STANDARD::JACK:
    os << "JACK";
    break;
  case STANDARD::QUEEN:
    os << "QUEEN";
    break;
  case STANDARD::KING:
    os << "KING";
    break;
  case STANDARD::JOKER:
    os << "JOKER";
    break;
  default:
    break;
  }
  
  return os;
}

} // ! namespace denomenations

#endif // ! denomenations.h
