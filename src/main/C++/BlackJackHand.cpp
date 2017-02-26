#include "BlackJackHand.h"
#include <cstdint>
#include <list>
#include <boost/optional.hpp>

namespace blackjack
{

  bool BlackJackHand::twenty_one() const noexcept
  {
    return this->value() == 21;
  }

  bool BlackJackHand::busted() const noexcept
  {
    return this->value() > 21;
  }

  bool BlackJackHand::blackjack() const noexcept
  {
    return this->num_cards() == 2 && this->twenty_one();
  }

  uint8_t BlackJackHand::value() const
  {
    uint8_t val = 0;
    uint8_t num_aces = 0;
    boost::optional<uint8_t> ace_val_range; /// @todo - make const uint8_t if can

    auto en = this->cend();
    for(auto citer = this->cbegin(); citer != en; ++citer)
    {
      auto pCard = *citer;
      if (pCard->ace())
      {
	if (!ace_val_range.is_initialized())
	{
	  *ace_val_range = (pCard->max_value() - pCard->min_value());
	}
	++num_aces;
      }

      val += pCard->min_value();
    }

    while (num_aces-- > 0 && val < 21)
    {
      const uint8_t candidate_val = val + *ace_val_range;
      if (candidate_val > 21)
      {
	break;
      }
      else
      {
	val = candidate_val;
      }
    }

    return val;
  }

} // ! namespace blackjack
