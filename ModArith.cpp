#include "ModArith.h"

namespace CRY{
  val ModArith::cra(vector<val> r, vector<val> n){
    val k  = r.size();
    if(n.size() != k){
      std::cerr << "Error: Need same number of remainders and moduli\n";
      exit(1);
    }
    val m = 1;
    for(val i = 0; i < k; ++i){
      m *= n[i];
    }
    val mi;
    val ci;
    val x = 0;
    for(val i = 0; i < k; ++i){
      mi = m / n[i];
      ci = modInv(mi, n[i]);
      x += r[i] * ci * mi;
    }
    return x % m;
  }
  val ModArith::modInv(val a, val n){
    if(a == 0){
      std::cerr << "Error: No modular inverse exists\n";
      exit(1);
    }
    if(n == 1)
      return 0;
    if(a == 1)
      return 1;
    val e = totient(n) - 1;
    return modExp(a, e, n);
  }
  val ModArith::modExp(val a, val e, val n){
    val e2Size = static_cast<val>(log2(e)) + 1;
    if(e2Size >= 256){
      std::cerr << "Error: n too large\n";
      exit(1);
    }
    std::bitset<256> e2(e);
    val b = a;
    for(val i = e2Size - 2; i >= 0; --i){
      b = b * b % n;
      if(e2[i])
	b = b * a % n;
    }
    return b;
  }
  bool ModArith::isPrime(val n){
    return totient(n) == n - 1;
  }
  val ModArith::totient(val n){
    val tot = 1;
    for(val i = 2; i < n; ++i){
      if(gcd(i, n) == 1)
	++tot;
    }
    return tot;
  }
  val ModArith::gcd(val a, val b){
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
