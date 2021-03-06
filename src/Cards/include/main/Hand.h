#ifndef GUARD_HAND_H_
#define GUARD_HAND_H_

// C++
#include <list>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <cstdlib>

// boost
#include "boost/serialization/strong_typedef.hpp"
#include "boost/exception/all.hpp"

// Custom
#include "Error.h"
#include "Card.h"

namespace basic
{

  /*
   * A template class representing a basic
   * hand of cards. The class is templatized
   * on the Card type, which should be a subclass
   * of basic::Card.
   */
  template<typename Card>
  class Hand
  {
    // public aliases
  public:

    // Id
    BOOST_STRONG_TYPEDEF(int32_t, Id);

    // public structors
  public:

    /// @brief 1-parameter constructor.
    /// @param id Id of this Hand.
    explicit Hand(Id id);

    /// @brief 3-parameter constructor.
    /// @param first_card Iterator to first card of this Hand.
    /// @param last_card Iterator to last card of this Hand.
    /// @param id Id of this Hand.
    /// @note Client is responsible for providing the Hand Id and to check
    ///   for uniqueness.
    template<typename CardIter>
    explicit Hand( CardIter first_card
                 , CardIter last_card
                 , Id id
                 );

    /// @brief Copy constructor.
    /// @attention DELETED.
    Hand(const Hand&) = delete;

    /// @brief Copy-assignment operator.
    /// @attention DELETED.
    Hand& operator=(const Hand&) = delete;

    /// @brief Move constructor.
    /// @attention DELETED.
    Hand(Hand&&) = delete;

    /// @brief Move-assignment operator.
    /// @attention DELETED.
    Hand& operator=(Hand&&) = delete;

    /// @brief Destructor.
    virtual ~Hand() = default;

    // public member functions
  public:

    /// @brief Add a card to this Hand.
    /// @param card The Card to be added to this Hand.
    ///  A nullptr will not be disregarded.
    void add_card(const Card* card);

    /// @brief Play a card from this Hand.
    /// @param idx Index of the Card to play. Indices start from 0.
    /// @return The Card that was played.
    const Card* play_card(typename std::list<const Card*>::size_type idx);

    /// @brief Play a random card from this Hand.
    /// @return The Card that was played.
    const Card* play_card();

    /// @brief Peek at a card from this Hand.
    /// @param idx Index of the Card to peek. Indices start from 0.
    /// @return The Card that was peeked.
    const Card* peek_card(typename std::list<const Card*>::size_type idx) const;

    /// @brief Peek at a random card of this Hand.
    /// @return The Card that was peeked.
    const Card* peek_card() const;

    /// @brief Get a const iterator to the first card of this Hand.
    /// @return A const iterator to the first Card of this Hand.
    typename std::list<const Card*>::const_iterator
    cbegin() const noexcept;

    /// @brief Get a constant iterator to one past the last card of this Hand.
    /// @return A const iterator to the last Card of this Hand.
    typename std::list<const Card*>::const_iterator
    cend() const noexcept;

    /// @brief Get the number of Cards associated with this Hand.
    /// @return The number  of Cards associated with this Hand.
    typename std::list<const Card*>::size_type num_cards() const noexcept;

    /// @brief Get the id of this Hand.
    /// @return the id of this Hand.
    Id id() const noexcept;

    /// @brief pretty print this Hand.
    /// @param os The stream to which to serialize this Hand.
    void print(std::ostream& os) const noexcept;

    // private member functions.
  private:

    /// @brief Get a card from this Hand.
    /// @param idx Index of the Card to get. Indices start from 0.
    /// @return A const iterator to the specified Card.
    typename std::list<const Card*>::const_iterator
    get_card(typename std::list<const Card*>::size_type idx) const;

    // private data members.
   private:

    typename std::list<const Card*> m_cards;
    Id m_id;

  }; // ! class Hand

  /// @brief Inserter for Hand class.
  /// @param os Output stream to which data is to be serialised.
  /// @param hand The Hand object that is to be serialised.
  /// @return The updated version of the output stream specified.
  template<typename Card>
  std::ostream& operator<<(std::ostream& os, const Hand<Card>& hand);

  //----------------- Hand member function defintiions -----------------------//

  template<typename Card>
  template<typename CardIter>
  Hand<Card>::Hand( CardIter first_card
                  , CardIter last_card
                  , Id id
                  )
    : m_cards(first_card, last_card)
    , m_id(id)
  {
    /*
    /// @todo - enable this
    stdtic_assert( std::is_same< std::remove_const<typename std::iterator_traits<CardIter>::value_type>::type::value
                               , Card*
                               >::type::value
                 , "CardIter has a value type that is not compatible."
                 );
    */
  }

  template<typename Card>
  Hand<Card>::Hand(Id id)
    : m_id(id)
  {}

  template<typename Card>
  void Hand<Card>::add_card(const Card* card)
  {
    if (card != nullptr)
    {
      m_cards.push_back(card);
    }
  }

  template<typename Card>
  typename std::list<const Card*>::const_iterator
  Hand<Card>::get_card(typename std::list<const Card*>::size_type idx) const
  {
    if (num_cards() < (idx + 1))
    {
      /// @todo - wrap this up in a macro taking the idx as the argument.
      error::get_card_with_invalid_index e;
      e << basic::error::get_card_with_invalid_index_info(idx);
      BOOST_THROW_EXCEPTION(e);
    }

    auto iter {m_cards.cbegin()};
    std::advance(iter, idx);

    return iter;
  }

  template<typename Card>
  const Card*
  Hand<Card>::play_card(typename std::list<const Card*>::size_type idx)
  {
    auto iter = this->get_card(idx);
    const Card* ret = *iter;
    m_cards.erase(iter);
    return ret;
  }

  template<typename Card>
  const Card*
  Hand<Card>::play_card()
  {
    return this->play_card(0);
  }

  template<typename Card>
  const Card*
  Hand<Card>::peek_card(typename std::list<const Card*>::size_type idx) const
  {
    auto iter = this->get_card(idx);
    return *iter;
  }

  template<typename Card>
  const Card*
  Hand<Card>::peek_card() const
  {
    return this->peek_card(0);
  }

  template<typename Card>
  typename std::list<const Card*>::const_iterator
  Hand<Card>::cbegin() const noexcept
  {
    return m_cards.cbegin();
  }

  template<typename Card>
  typename std::list<const Card*>::const_iterator
  Hand<Card>::cend() const noexcept
  {
    return m_cards.cend();
  }

  template<typename Card>
  typename std::list<const Card*>::size_type
  Hand<Card>::num_cards() const noexcept
  {
    return m_cards.size();
  }

  template<typename Card>
  typename Hand<Card>::Id Hand<Card>::id() const noexcept
  {
    return m_id;
  }

  template<typename Card>
  void Hand<Card>::print(std::ostream& os) const noexcept
  {
    os << "<Hand>\n";
    for (auto card : m_cards)
    {
      os << "\t" << *card << "\n";
    }
    os << "</Hand>";
    os.flush();
  }

  template<typename Card>
  std::ostream& operator<<(std::ostream& os, const Hand<Card>& hand)
  {
    hand.print(os);
    return os;
  }

} // ! namespace basic

#endif // ! GUARD_HAND_H_
