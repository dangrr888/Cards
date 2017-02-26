#ifndef GUARD_BLACKJACKCARD_H_
#define GUARD_BLACKJACKCARD_H_

#include "Card.h"
#include <cstdint>
#include "BlackJackSuits.h"
#include "BlackJackDenomenations.h"

namespace blackjack
{
  class BlackJackCard
    : public basic::Card< blackjack::BLACKJACKSUIT
                        , blackjack::BLACKJACKDENOMENATION
                        >
  {
    // public etters
  public:

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

} // ! namespace blackjack

#endif // ! GUARD_BLACKJACKCARD_H_
