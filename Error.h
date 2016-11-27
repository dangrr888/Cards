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

  struct deal_from_empty_deck : std::exception
  {
    const char* what() const noexcept {return "Attempt to deal card from empty Deck."; }
  };

} // !namespace basic

#endif // !GUARD_ERROR_H_
