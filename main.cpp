#include <cstdlib>
#include <iostream>
#include <list>

#include "suits.h"
#include "denomenations.h"
#include "Deck.h"
#include "Card.h"

int main(int argc, char* argv[])
{
  // Create a Card
  using suit = suits::STANDARD;
  using denom = denomenations::STANDARD;
  using card = basic::Card<suit, denom>;
  using deck = basic::Deck<card>;

  const card ace_of_spades(suit::HEARTS, denom::ACE);

  /// @todo - replace this with an inserter for a card.
  ///  \code{.cpp}
  ///  std::cout << "ace_of_spaces: " << ace_of_spades << std::endl;
  ///  \endcode
  std::cout << "suit: " << ace_of_spades.suit() << std::endl;
  std::cout << "denom: " << ace_of_spades.denomenation() << std::endl;

  /// @todo - why am i doing this? More and more reasons to make these enums classes.
  ///  since most of the time the user will want to add all the permutations.
  const std::list<suit> suits {suit::HEARTS, suit::DIAMONDS, suit::SPADES, suit::CLUBS};
  const std::list<denom> denoms
  {
    denom::ACE,
    denom::TWO,
    denom::THREE,
    denom::FOUR,
    denom::FIVE,
    denom::SIX,
    denom::SEVEN,
    denom::EIGHT,
    denom::NINE,
    denom::TEN,
    denom::JACK,
    denom::QUEEN,
    denom::KING
  };

  /// @todo - add 3-parameter Deck constructor and Deck::add_card so that we can add Jokers.

  // Create a Deck
  basic::Deck<card> standard_deck( suits.cbegin()
				 , suits.cend()
				 , denoms.cbegin()
				 , denoms.cend()
				 , deck::Id{1}
				 );

  std::cout << "number of undealt cards: " << standard_deck.num_undealt_cards()
            << ", number dealt cards: " << standard_deck.num_dealt_cards()
            << std::endl;

  // Get a card...any card
  card dealt_card = standard_deck.deal_card();
  std::cout << "Dealt card suit: " << dealt_card.suit()
            << ", Dealt card denomenation: " << dealt_card.denomenation()
            << std::endl;

  std::cout << "number of undealt cards: " << standard_deck.num_undealt_cards()
            << ", number dealt cards: " << standard_deck.num_dealt_cards()
            << std::endl;

  return EXIT_SUCCESS;
}
