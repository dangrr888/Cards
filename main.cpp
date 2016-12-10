#include <cstdlib>
#include <iostream>
#include <list>

#include "suits.h"
#include "denomenations.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"

int main(int argc, char* argv[])
{
  // Create a Card
  using suit = suits::STANDARD;
  using denom = denomenations::STANDARD;
  using card = basic::Card<suit, denom>;
  using deck = basic::Deck<card>;
  using hand = basic::Hand<card>;

  const card ace_of_spades(suit::HEARTS, denom::ACE);

  std::cout << "ace_of_spaces:\n" << ace_of_spades << std::endl;

  /// @todo - why am i doing this? More and more reasons to make these enums classes.
  ///  since most of the time the user will want to add all the permutations.
  /// but wont get that unless we wrap suits and denomenations with iteratorable classes.
  const std::list<suit> suits
  {
    suit::HEARTS,
    suit::DIAMONDS,
    suit::SPADES,
    suit::CLUBS
  };

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

  // Create a Deck
  basic::Deck<card> standard_deck( suits.cbegin()
				 , suits.cend()
				 , denoms.cbegin()
				 , denoms.cend()
				 , deck::Id{1}
				 );

  // Add Joker's
  for (int i = 0; i < 2; ++i)
  {
    standard_deck.add_card(card(suit::NONE, denom::JOKER));
  }

  // Print Deck stats before dealing cards
  std::cout << "standard deck BEFORE dealing:\n"
            << standard_deck
            << std::endl;

  std::cout << "number of undealt cards: " << standard_deck.num_undealt_cards()
            << ", number dealt cards: " << standard_deck.num_dealt_cards()
            << std::endl;

  // Deal a hand of cards
  hand dealt_hand(hand::Id{1});

  // Print Hand stats before dealing
  std::cout << "hand BEFORE dealing:\n"
            << dealt_hand
            << std::endl;

  std::cout << "number of cards in hand: " << dealt_hand.num_cards()
            << std::endl;

  for (int i = 0; i < 5; ++i)
  {
    dealt_hand.add_card(standard_deck.deal_card());
  }

  // Print Hand stats after dealing
  std::cout << "hand AFTER dealing:\n"
            << dealt_hand
            << std::endl;

  std::cout << "number of cards in hand: " << dealt_hand.num_cards()
            << std::endl;

  // Play cards exhaustively
  while(dealt_hand.num_cards() > 0)
  {
    const card& dealt_card = dealt_hand.play_card(0);
    std::cout << "Dealt card suit: " << dealt_card.suit()
              << ", Dealt card denomenation: " << dealt_card.denomenation()
              << std::endl;

    std::cout << "number of cards in hand: " << dealt_hand.num_cards()
              << std::endl;
  }

  // Print Hand stats after playing exhaustively
  std::cout << "hand AFTER dealing exhaustively:\n"
            << dealt_hand
            << std::endl;

  std::cout << "number of cards in hand: " << dealt_hand.num_cards()
            << std::endl;

  // Print Deck stats after dealing hand
  std::cout << "standard deck AFTER dealing hand:\n"
            << standard_deck
            << std::endl;

  std::cout << "number of undealt cards: " << standard_deck.num_undealt_cards()
            << ", number dealt cards: " << standard_deck.num_dealt_cards()
            << std::endl;

  // Deal cards until the Deck is empty
  while(standard_deck.num_undealt_cards() > 0)
  {
    std::cout << "number of undealt cards: " << standard_deck.num_undealt_cards()
              << ", number dealt cards: " << standard_deck.num_dealt_cards()
              << std::endl;

    // Deal a card...any card
    card dealt_card = standard_deck.deal_card();
    std::cout << "Dealt card suit: " << dealt_card.suit()
              << ", Dealt card denomenation: " << dealt_card.denomenation()
              << std::endl;
  }

  // Print Deck stats after dealing cards
  std::cout << "standard deck AFTER exhaustive dealing:\n"
            << standard_deck
            << std::endl;

  std::cout << "number of undealt cards: " << standard_deck.num_undealt_cards()
            << ", number dealt cards: " << standard_deck.num_dealt_cards()
            << std::endl;

  return EXIT_SUCCESS;
}
