#include <cstdlib>
#include <iostream>
#include <list>

#include "Deck.h"
#include "Card.h"

namespace example
{

enum class SUIT {HEARTS, DIAMONDS, SPADES, CLUBS};
enum class DENOMENATION 
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
};

} // ! namespace example

std::ostream& operator<<(std::ostream& os, const example::SUIT& suit)
{
  switch (suit)
  {
  case example::SUIT::HEARTS:
    std::cout << "HEARTS";
    break;
  case example::SUIT::DIAMONDS:
    std::cout << "DIAMONDS";
    break;
  case example::SUIT::SPADES:
    std::cout << "SPADES";
    break;
  case example::SUIT::CLUBS:
    std::cout << "CLUBS";
    break;
  default:
    break;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const example::DENOMENATION& denom)
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

/*
template<typename SUIT, typename DENOMENATION>
std::ostream& operator<<(std::ostream& os, const Card<SUIT, DENOMENATION>& card)
{
  os << "Card: SUIT: " << card.suit() << ", DENOM: " << card.denomenation();
  return os;
}
*/

int main(int argc, char* argv[])
{
  // Create a Card
  basic::Card<example::SUIT, example::DENOMENATION> ace_of_spades(example::SUIT::HEARTS, example::DENOMENATION::ACE);

  std::cout << "suit: " << ace_of_spades.suit() << std::endl;
  std::cout << "denom: " << ace_of_spades.denomenation() << std::endl;

  //std::cout << "ace_of_spaces: " << ace_of_spades << std::endl;

  const std::list<example::SUIT> suits {example::SUIT::HEARTS, example::SUIT::DIAMONDS, example::SUIT::SPADES, example::SUIT::CLUBS};
  const std::list<example::DENOMENATION> denoms
  {
    example::DENOMENATION::ACE,
    example::DENOMENATION::TWO,
    example::DENOMENATION::THREE,
    example::DENOMENATION::FOUR,
    example::DENOMENATION::FIVE,
    example::DENOMENATION::SIX,
    example::DENOMENATION::SEVEN,
    example::DENOMENATION::EIGHT,
    example::DENOMENATION::NINE,
    example::DENOMENATION::TEN,
    example::DENOMENATION::JACK,
    example::DENOMENATION::QUEEN,
    example::DENOMENATION::KING
  };

  basic::Deck<basic::Card<example::SUIT, example::DENOMENATION>> standard_deck( suits.cbegin()
                                                                                , suits.cend()
                                                                                , denoms.cbegin()
                                                                                , denoms.cend()
                                                                                , basic::Deck<basic::Card<example::SUIT, example::DENOMENATION>>::Id{1}
                                                                                );
                                                                                
  std::cout << standard_deck.num_cards() << std::endl;
                                                                                
  return EXIT_SUCCESS;
}
