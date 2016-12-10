#ifndef GUARD_CARD_H_
#define GUARD_CARD_H_

#include "suits.h"
#include "denomenations.h"
#include <iostream>

namespace basic
{

  /* A template class representing a 
   * basic Card. The class is sufficiently
   * generic to be templatised for any
   * suit or denomenation provided by the
   * client.
   */
  template<typename SUIT, typename DENOMENATION>
  class Card
  {
    // static assertions

    static_assert( (std::is_enum<SUIT>::value && std::is_enum<DENOMENATION>::value)
                 , "suit and denomenation of this Card must be enum's."
                   );

    // public constructors    
  public:
    
    /// @brief 2-parameter constructor.
    /// @param suit SUIT of this Card.
    /// @param denom DENOMENATION of this Card.
    explicit Card(SUIT suit, DENOMENATION denom);
    
    /// @brief Copy constructor.
    Card(const Card&) = default;
    
    /// @brief Copy assignment operator.
    Card& operator=(const Card&) = default;

    /// @brief Move Constructor.
    Card(Card&&) = default;

    /// @brief Move assignement operator.
    Card& operator=(Card&&) = default;
    
    /// @brief Destructor.
    virtual ~Card() = default;

    // public member functions
  public:

    /// @brief Accessor for suit of this Card.
    /// @return suit of this Card.
    constexpr SUIT suit() const noexcept;
    
    /// @brief Accessor for denomenation of this Card.
    /// @return denomenation of this Card.
    constexpr DENOMENATION denomenation() const noexcept;

    // private data members
  private:

    const SUIT m_suit;
    const DENOMENATION m_denomenation;
    
  }; // !class Card

  /// @brief Inserter for Card class.
  /// @param os Output stream to which data is to be serialised.
  /// @param card The Card object that is to be serialised.
  /// @return The updated version of the output stream specified.
  template<typename S, typename D>
  std::ostream& operator<<(std::ostream& os, const Card<S, D>& card);

  //------------ Card - member function definitions ---------------------------- //

  template<typename SUIT, typename DENOMENATION>
  Card<SUIT, DENOMENATION>::Card(SUIT suit, DENOMENATION denom)
    : m_suit(suit)
    , m_denomenation(denom)
  {}
  
  template<typename SUIT, typename DENOMENATION>
  constexpr SUIT Card<SUIT, DENOMENATION>::suit() const noexcept
  {
    return m_suit;
  }
  
  template<typename SUIT, typename DENOMENATION>
  constexpr DENOMENATION Card<SUIT, DENOMENATION>::denomenation() const noexcept
  {
    return m_denomenation;
  }

  template<typename S, typename D>
  std::ostream& operator<<(std::ostream& os, const Card<S, D>& card)
  {
    os << "<Card "
       << "suit=\"" << card.suit() << "\", "
       << "denomenation=\"" << card.denomenation() << "\""
       << ">";
    
    return os;
  }
  
} // ! namespace basic

#endif // !GUARD_CARD_H_
