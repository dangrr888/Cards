#ifndef GUARD_CARD_HPP_
#define GUARD_CARD_HPP_

#include "Suit.hpp"
#include "Denomination.hpp"

namespace Card
{

/// @brief A class to represent a generic card
///  templatized on its suit and denomination
///  which can be any collection of unique values.
template<typename SUIT, typename DENOMINATION>
class Card
{
 // public structors 
 public:
  /// @brief 2-parameter Constructor
  /// @param suit The SUIT of this Card.
  /// @param denom The denomination of this Card.
  explicit Card(const SUIT& suit, const DENOMINATION& denom);

  /// @brief Destructor
  /// @note virtual function.
  virtual ~Card() = default;

  /// @brief Copy constructor
  /// @note deleted
  Card(const Card&) = delete;
  
  /// @brief Copy assignment operator
  /// @note deleted
  Card& operator=(const Card&) = delete;
  
  /// @brief Move constructor
  /// @note deleted.
  Card(Card&&) = delete;

  /// @brief Move assignment constructor
  /// @note deleted.
  Card& operator==(Card&&) = delete;

 // public etters 
 public:
  
  /// @brief Get SUIT of this Card.
  /// @return The SUIT of this Card. 
  SUIT suit() const;

  /// @brief Get DENOMINATION of this Card.
  /// @return The DENOMINATION of this Card. 
  DENOMINATION denomination() const;
 
 // private data members
 private:
  /// @brief The SUIT of this card.
  /// @note This is constant.
  const SUIT m_suit;

  /// @brief The DENOMINATION of this card.
  /// @note This is constant.
  const DENOMINATION m_denom;

}; // class Card


// ---------------Card member function definitions------------------------

template<typename SUIT, typename DENOMINATION>
Card<SUIT, DENOMINATION>::Card(const SUIT& suit, const DENOMINATION& denom)
  : m_suit(suit)
  , m_denom(denom)
{}

template<typename SUIT, typename DENOMINATION>
typename SUIT Card<SUIT, DENOMINATION>::suit() const
{
  return m_suit;
}

template<typename SUIT, typename DENOMINATION>
typename SUIT Card<SUIT, DENOMINATION>::demonination() const
{
  return m_denom;
}

// !---------------Card member function definitions-----------------------

} // ! namespace Card

#endif // ! GUARD_CARD_HPP_
