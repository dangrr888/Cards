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
    // public structors
  public:
    /// @brief 1-parameter constructor.
    /// @param id Id of this Hand.
    explicit BlackJackHand(Id id);

    /// @brief 3-parameter constructor.
    /// @param first_card Iterator to first card of this Hand.
    /// @param last_card Iterator to last card of this Hand.
    /// @param id Id of this Hand.
    /// @note Client is responsible for providing the Hand Id and to check
    ///   for uniqueness.
    template<typename BlackJackCardIter>
    BlackJackHand( BlackJackCardIter first_card
                 , BlackJackCardIter last_card
                 , Id id
                 );

    /// @brief Copy constructor.
    /// @attention DELETED.
    BlackJackHand(const BlackJackHand&) = delete;

    /// @brief Copy-assignment operator.
    /// @attention DELETED.
    BlackJackHand& operator=(const BlackJackHand&) = delete;

    /// @brief Move constructor.
    /// @attention DELETED.
    BlackJackHand(BlackJackHand&&) = delete;

    /// @brief Move-assignment operator.
    /// @attention DELETED.
    BlackJackHand& operator=(BlackJackHand&&) = delete;

    /// @brief Destructor.
    virtual ~BlackJackHand() = default;

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

  /// @brief Inserter for BlackJackHand class.
  /// @param os Output stream to which data is to be serialised.
  /// @param bjhand The BlackJackHand object that is to be serialised.
  /// @return The updated version of the output stream specified.
  std::ostream& operator<<(std::ostream& os, const BlackJackHand& bjhand);

  //----------------- BlackJackHand member function defintiions --------------//

  template<typename BlackJackCardIter>
  BlackJackHand::BlackJackHand( BlackJackCardIter first_card
                , BlackJackCardIter last_card
                , Id id
                )
     : Hand(first_card, last_card, id)
  {}

} // ! namespace blackjack

#endif // ! GUARD_BLACKJACKHAND_H_
