#include "modArith.h"

namespace cry{
  unsigned long modArith::modInv(int a, int n){
    if(a == 0){
      std::cerr << "Error: No modular inverse exists\n";
      exit(1);
    }
    if(n == 1)
      return 0;
    if(a == 1)
      return 1;
    unsigned long e = totient(n) - 1;
    return modExp(a, e, n);
  }
  unsigned long modArith::modExp(int a, int e, int n){
    int e2Size = static_cast<int>(log2(e)) + 1;
    if(e2Size >= 256){
      std::cerr << "Error: n too large\n";
      exit(1);
    }
    std::bitset<256> e2(e);
    int b = a;
    for(int i = e2Size - 2; i >= 0; --i){
      b = b * b % n;
      if(e2[i])
	b = b * a % n;
    }
    return b;
  }
  unsigned long modArith::totient(int n){
    int tot = 1;
    for(int i = 2; i < n; ++i){
      if(gcd(i, n) == 1)
	++tot;
    }
    return tot;
  }
  unsigned long modArith::gcd(int a, int b){
    if(a == 0)
      return b;
    if(b == 0)
      return a;
    if(a % 2 == 0 && b % 2 == 0)
      return 2*gcd(a/2, b/2);
    if(a % 2 == 0)
      return gcd(a/2, b);
    if(b % 2 == 0)
      return gcd(a, b/2);
    if(a >= b)
      return gcd((a - b)/2, b);
    else
      return gcd((b - a)/2, a);
  }
}
