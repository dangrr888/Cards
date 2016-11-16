#ifndef GUARD_CARD_H_
#define GUARD_CARD_H_

namespace basic
{

template<typename SUIT, typename DENOMENATION>
class Card
{
 public:

  // public constructors

  /// @brief 2-parameter constructor.
  /// @param suit SUIT of this Card.
  /// @param denom DENOMENATION of this Card.
  explicit Card(SUIT suit, DENOMENATION denom);

  /// @brief destructor.
  ~Card() = default;
  
  /// @brief Copy constructor.
  Card(const Card&) = default;

  /// @brief Copy assignment operator.
  Card& operator=(const Card&) = default;

  /// @brief Move Constructor.
  Card(Card&&) = default;

  /// @brief Move assignement operator.
  Card& operator=(Card&&) = default;

  // public accessors

  /// @brief get SUIT of this Card.
  /// @return SUIT of this Card.
  constexpr SUIT suit() const noexcept;

  /// @brief get DENOMENATION of this Card.
  /// @return DENOMENTATION of this Card.
  constexpr DENOMENATION denomenation() const noexcept;

 private:

  // private data members

  const SUIT m_suit;
  const DENOMENATION m_denomenation;

}; // !class Card

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

} // !namespace basic

#endif // !GUARD_CARD_H_
