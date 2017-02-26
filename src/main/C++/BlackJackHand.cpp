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
    uint4_t num_aces = 0;
    boost::optional<uint4_t> ace_val_range; /// @todo - make const uint4_t if can

    auto en = this->cend();
    for(auto citer = this->cbegin(); citer != en; ++citer)
    {
      if (citer->ace())
      {
	if (!ace_val_range.is_initialized())
	{
	  *ace_val_range = (citer->max_value() - citer->min_value());
	}
	++num_aces;
      }

      val += citer->min_value();
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
