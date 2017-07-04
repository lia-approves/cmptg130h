#include <limits>
#include <cmath>
#include <iostream>

namespace CRY{
  class DiffieHellman{
  public:
    static unsigned long keyGen();
    static unsigned long maxUInt(){
      return std::numeric_limits<unsigned int>::max();
    }
    static unsigned long maxULong(){
      return std::numeric_limits<unsigned long>::max();
    }
    static unsigned long long maxULongLong(){
      return std::numeric_limits<unsigned long long>::max();
    }

  };
}
