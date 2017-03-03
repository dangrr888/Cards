#ifndef GUARD_BLACKJACKCARD_H_
#define GUARD_BLACKJACKCARD_H_

#include "Card.h"
#include "BlackJackSuits.h"
#include "BlackJackDenomenations.h"

#include <cstdint>
#include <iostream>

namespace blackjack
{
  class BlackJackCard
    : public basic::Card< blackjack::BLACKJACKSUIT
                        , blackjack::BLACKJACKDENOMENATION
                        >
  {
    // public etters
  public:
    /// @brief 2-parameter constructor.
    /// @param suit The BLACKJACKSUIT of this BlackJackCard.
    /// @param denom The BLACKJACKDENOMENATION of this BlackJackCard.
    BlackJackCard( blackjack::BLACKJACKSUIT suit
                 , blackjack::BLACKJACKDENOMENATION denom
                 );

    /// @brief Get whether this BlackJackCard is an ACE.
    /// @return Whether this BlackJackCard is an ACE.
    bool ace() const noexcept;

    /// @brief Get the minimum value of this BlackJackCard.
    /// @detail For an ACE, this will return 1. For other
    ///  non-face cards this returns the number associated
    ///  with the card denomenation (e.g., 10 for TEN).
    ///  For face cards this returns 10.
    /// @return The minimum value of this BlackJackCard.
    std::uint8_t min_value() const noexcept;

    /// @brief Get the maximum value of this BlackJackCard.
    /// @detail For an ACE, this will return 11. For other
    ///  this returns the result from min_value().
    /// @return The maximum value of this BlackJackCard.
    std::uint8_t max_value() const noexcept;

  }; // ! class BlackJackCard

  /// @brief Inserter for BlackJackCard class.
  /// @param os Output stream to which data is to be serialised.
  /// @param card The BlackJackCard object that is to be serialised.
  /// @return The updated version of the output stream specified.
  std::ostream& operator<<(std::ostream& os, const BlackJackCard& bjcard);

} // ! namespace blackjack

#endif // ! GUARD_BLACKJACKCARD_H_
