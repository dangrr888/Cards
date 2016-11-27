#ifndef GUARD_DECK_H_
#define GUARD_DECK_H_

// C++
#include <list>
#include <cstdint>
#include <utility>
#include <type_traits>
#include <ctime>
#include <iterator>
#include <stdexcept>
// Boost
#include "boost/serialization/strong_typedef.hpp"
#include "boost/random.hpp"
// Custom
#include "Card.h"

namespace basic
{

  /*
   * A template class representing a basic
   * deck of cards. The class is templatized
   * on the Card type, which must be a subclass
   * of basic::Card.
   */
  template<typename Card>
  class Deck
  {
    // @todo - add static assert to ensure that Card has specific interface
    // static assertions
    /*
    static_assert( ( std::is_base_of<basic::Card, Card>::value || 
                     std::is_same<basic::Card, Card>::value
                    )
                 , "Cards in this Deck must be derived from basic::Card."
                 );
    */

    // public aliases    
  public:

    // Id
    BOOST_STRONG_TYPEDEF(int32_t, Id);
    
    // public structors
  public:
    
    /// @brief 5-parameter constructor.
    /// @param first_suit Iterator to first suit of this Deck.
    /// @param last_suit Iterator to last suit of this Deck.
    /// @param first_denom Iterator to first denomenation of this Deck.
    /// @param last_denom Iterator to last denomenation of this Deck.
    /// @param id Id of this Deck.
    /// @note Client is responsible for providing the Deck Id and to check
    ///  for uniqueness.
    template<typename SuitIter, typename DenomIter>
    explicit Deck( SuitIter first_suit
                 , SuitIter last_suit
                 , DenomIter first_denom
		 , DenomIter last_denom
		 , Id id
		 );

    /// @brief 3-parameter constructor.
    /// @param first_card iterator to the first card of this Deck.
    /// @param first_card iterator to the last card of this Deck.
    /// @param id Id of this Deck.
    /// @note Client is responsible for providing the Deck Id and to check
    ///  for uniqueness.
    template<typename CardIter iter>
    explicit Deck( CardIter first_card
		 , CardIter last_card
		 , Id id
		 );
    
    /// @brief Copy constructor.
    /// @attention DELETED
    Deck(const Deck&) = delete;

    /// @brief Copy assignment operator.
    /// @attention DELETED
    Deck& operator=(const Deck&) = delete;

    /// @brief Move constructor.
    /// @attention DELETED
    Deck(Deck&&) = delete;
    
    /// @brief Move assignment operator.
    /// @attention DELETED
    Deck& operator=(Deck&&) = delete;
    
    /// @brief Destructor.
    virtual ~Deck() = default;
    
    /// public member functions
  public:

#if 0
    /// Add a Card to this Deck.
    /// @param card Card to be added.
    /// @attention NOT YET IMPLEMENTED.
    void add_card(const Card& card);
#endif    

    /// @brief Get a random un-dealt Card of this Deck.
    /// @detail Dealing a Card renders it dealt.
    /// @return A random un-dealt Card of this Deck.
    /// @pre The number of undealt cards must be greater than zero
    ///  otherwise this function will throw an exception.
    Card& deal_card();
    
    /// @brief Get number of Cards in this Deck.
    /// @return The number of Cards in this Deck.
    typename std::list<Card>::size_type num_cards() const noexcept;
    
    /// @brief Get the id of this Deck.
    /// @return the id of this Deck.
    Id id() const noexcept;

    /// @brief Get number of un-dealt Cards in this Deck.
    /// @return The number of un-dealt Cards in this Deck.
    typename std::list<Card>::size_type num_undealt_cards() const noexcept;

    /// @brief Get number of dealt Cards in this Deck.
    /// @return The number of dealt Cards in this Deck.
    typename std::list<Card>::size_type num_dealt_cards() const noexcept;

    // private data members
  private:

    typename std::list<Card> m_undealt_cards;
    typename std::list<Card> m_dealt_cards;
    Id m_id;

  }; // ! class Deck
  
  //----------------- Deck member function defintiions -----------------------//

  template<typename Card>
  template<typename SuitIter, typename DenomIter>
  Deck<Card>::Deck( SuitIter first_suit
                  , SuitIter last_suit
                  , DenomIter first_denom
                  , DenomIter last_denom
                  , Id id
                  )
    : m_undealt_cards()
    , m_dealt_cards()
    , m_id(id)
  {
    for(SuitIter suit = first_suit; suit != last_suit; ++suit)
    {
      for(DenomIter denom = first_denom; denom != last_denom; ++denom)
      {
        m_undealt_cards.push_back(std::move(Card(*suit, *denom)));
      }
    }
  }

  template<typename Card>
  template<typename CardIter iter>
  Deck<Card>::Deck( CardIter first_card
                  , CardIter last_card
                  , Id id
                  )
    : m_undealt_cards()
    , m_dealt_cards()
    , m_id(id)
  {
    for (CardIter iter = first_card; iter != last_card; ++iter)
    {
      m_undealt_cards.push_back(std::move(*iter));
    }
  }
  
  template<typename Card>
  Card& Deck<Card>::deal_card()
  {
    const typename std::list<Card>::size_type n {num_undealt_cards()};
    if (n == 0)
    {
      /// @todo Use boost error to get better error messages.
      throw std::logic_error("All cards have been dealt!");
    }
    
    const std::time_t now = std::time(0);
    boost::random::mt19937 gen{static_cast<std::uint32_t>(now)};
    boost::random::uniform_int_distribution<> dist{0, static_cast<int>(n-1)};
    auto distance {dist(gen)};

    auto iter {m_undealt_cards.cbegin()};
    std::advance(iter, distance);
    
    // move undealt card to dealt list
    m_dealt_cards.push_back(*iter); // @todo - would be great if we could move this.
    m_undealt_cards.erase(iter);
    
    return m_dealt_cards.back();
  }
  
  template<typename Card>
  typename std::list<Card>::size_type Deck<Card>::num_cards() const noexcept
  {
    return m_undealt_cards.size() + m_dealt_cards.size();
  }
   
  template<typename Card>
  typename Deck<Card>::Id Deck<Card>::id() const noexcept
  {
    return m_id;
  }
 
  template<typename Card>
  typename std::list<Card>::size_type Deck<Card>::num_undealt_cards() const noexcept
  {
    return m_undealt_cards.size();
  }

  template<typename Card>
  typename std::list<Card>::size_type Deck<Card>::num_dealt_cards() const noexcept
  {
    return m_dealt_cards.size();
  }

  /*
  template<typename SUIT, typename STANDARD>
  std::ostream& operator<<(std::ostream& os, const Card<SUIT, STANDARD>& card)
  {
    os << "Card: SUIT: " << card.suit() << ", DENOM: " << card.denomenation();
    return os;
  }
  */
 
} // ! namespace basic

#endif // ! GUARD_DECK_H_
