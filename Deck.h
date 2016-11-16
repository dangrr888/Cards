#ifndef GUARD_DECK_H_
#define GUARD_DECK_H_

#include <list>
#include <cstdint>
#include <boost/serialization/strong_typedef.hpp>
#include <utility>

namespace basic
{

template<typename Card>
class Deck
{
 public:
  
  // public aliases
  BOOST_STRONG_TYPEDEF(int32_t, Id);

  // public structors

  /// @brief 5-parameter constructor
  template<typename SuitIter, typename DenomIter>
  Deck( SuitIter first_suit
      , SuitIter last_suit
      , DenomIter first_denom
      , DenomIter last_denom
      , Id id
      );

  Deck(const Deck&) = delete;
  Deck& operator=(const Deck&) = delete;
  Deck(Deck&&) = delete;
  Deck& operator=(Deck&&) = delete;

  Card& get_card() const;
  
  typename std::list<Card>::size_type num_cards() const;
  Id id() const;

 private:
  typename std::list<Card> m_cards;
  Id m_id;

}; // ! class Deck

template<typename Card>
template<typename SuitIter, typename DenomIter>
Deck<Card>::Deck( SuitIter first_suit
                , SuitIter last_suit
                , DenomIter first_denom
                , DenomIter last_denom
                , Id id
                )
  : m_cards()
  , m_id(id)
{
  for(SuitIter suit = first_suit; suit != last_suit; ++suit)
  {
    for(DenomIter denom = first_denom; denom != last_denom; ++denom)
    {
      m_cards.push_back(std::move(Card(*suit, *denom)));
    }
  }
}

template<typename Card>
Card& Deck<Card>::get_card() const
{
  return *m_cards.begin();
}

template<typename Card>
  typename std::list<Card>::size_type Deck<Card>::num_cards() const
{
  return m_cards.size();
}

template<typename Card>
typename Deck<Card>::Id Deck<Card>::id() const
{
  return m_id;
}

} // ! namespace basic

#endif // ! GUARD_DECK_H_
