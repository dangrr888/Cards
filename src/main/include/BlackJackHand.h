#ifndef GUARD_BLACKJACKHAND_H_
#define GUARD_BLACKJACKHAND_H_

#include "Hand.h"
#include "BlackJackCard.h"
#include <cstdint>

namespace blackjack
{

  class BlackJackHand
    : public basic::Hand<blackjack::BlackJackCard>
  {
    // public etters
  public:

    /// @brief Get whether this BlackJackHand has a value of 21.
    /// @return If the value of this BlackJackHand is 21.
    bool twenty_one() const noexcept;

    /// @brief Get whether this BlackJackHand is busted.
    /// @return If the value of this BlackJackHand is busted.
    bool busted() const noexcept;

    /// @brief Get whether this BlackJackHand is blackjack.
    /// @return If this BlackJackHand is blackjack.
    bool blackjack() const noexcept;

    /// @brief Get the value of this BlackJackHand.
    /// @return The value of this BlackJackHand.
    uint8_t value() const;

  }; // ! class BlackJackHand

} // ! namespace blackjack

#endif // ! GUARD_BLACKJACKHAND_H_
