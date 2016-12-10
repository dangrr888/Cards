#ifndef GUARD_ERROR_H_
#define GUARD_ERROR_H_

// C++
#include <string>
#include <stdexcept>

// Boost
#include "boost/exception/all.hpp" 

namespace basic
{
  
  using errmsg_info = boost::error_info<struct tag_errmsg, std::string>;

  // deal_from_empty_deck
  struct deal_from_empty_deck : std::exception
  {
    const char* what() const noexcept { return "Attempt to deal card from empty Deck."; }
  };

  // play_card_with_invalid_index
  struct play_card_with_invalid_index : std::exception
  {
    const char* what() const noexcept { return "Attempt to play a card with invalid index."; }
  };
  
} // ! namespace basic

#endif // ! GUARD_ERROR_H_
