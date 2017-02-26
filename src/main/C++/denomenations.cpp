#include "denomenations.h"

#include <iostream>

namespace denomenations /// @todo - change this to basic namespace
{

   std::ostream& operator<<(std::ostream& os, STANDARD denom)
   {
     switch (denom)
     {
     case STANDARD::ACE:
       os << "ACE";
       break;
     case STANDARD::TWO:
       os << "TWO";
       break;
     case STANDARD::THREE:
       os << "THREE";
       break;
     case STANDARD::FOUR:
       os << "FOUR";
       break;
     case STANDARD::FIVE:
       os << "FIVE";
       break;
     case STANDARD::SIX:
       os << "SIX";
       break;
     case STANDARD::SEVEN:
       os << "SEVEN";
       break;
     case STANDARD::EIGHT:
       os << "EIGHT";
       break;
     case STANDARD::NINE:
       os << "NINE";
       break;
     case STANDARD::TEN:
       os << "TEN";
       break;
     case STANDARD::JACK:
       os << "JACK";
       break;
     case STANDARD::QUEEN:
       os << "QUEEN";
       break;
     case STANDARD::KING:
       os << "KING";
       break;
     case STANDARD::JOKER:
       os << "JOKER";
       break;
     default:
       break;
     }

     return os;
   }

 } // ! Namespace Denomenations
