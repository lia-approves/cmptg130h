#include "ModArith.h"
namespace CRY{

  val discriminant(val a, val b, val c, val d){
    return pow(b, 2)*pow(c, 2) - 4*a*pow(c, 3) - 4*pow(b, 3)*d - 27*pow(a, 2)*pow(d, 2) + 18*a*b*c*d;
  }
  
  val discriminantWeierstrass(val a, val b){
    return 4*pow(a, 3) + 27*pow(b, 2);
  }
  
  val ECCRNG(){
    return 0;
  }
  
  vector<val> ModArith::fastPrimes(val nMax){
    vector<val> ret;
    for(val i = 0; i <= nMax; ++i){
      for(val j = 0; j <= i; ++j){
	val q = (1 << i) + (1 << j) + 1;
        if(isPrime(q)){
	  ret.push_back(q);
	}
      }
    }
    return ret;
  }

  vector<val> ModArith::ZStarGroupElements(val n){
    vector<val> ret;
    if(isPrime(n)){
      for(val i = 0; i < n; ++i){
	ret.push_back(i);
      }
    }else{
      for(val i = 0; i < n; ++i){
	if(gcd(i, n) == 1){
	  ret.push_back(i);
	}
      }
    }
    return ret;
  }

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
    if(gcd(a, n) != 1){
      std::cerr << "Error: No modular inverse exists\n";
      exit(1);
    }
    val e = totient(n) - 1;
    return modExp(a, e, n);
  }

  val ModArith::modExp(val a, val e, val n){
    //modify maximum e2MaxSize if val is modified
    const val e2MaxSize = static_cast<val>(log2(ULLONG_MAX) + 1);
    val e2Size = static_cast<val>(log2(e)) + 1;
    if(e2Size >= e2MaxSize){
      std::cerr << "Error: e too large\n";
      exit(1);
    }
    unique_ptr<std::bitset<e2MaxSize>> e2 (new std::bitset<e2MaxSize>(e));
    val b = a;
    for(val i = e2Size - 1; i > 0; --i){
      b = b * b % n;
      if((*e2)[i-1])
	b = b * a % n;
    }
    return b;
  }

  bool ModArith::isPrime(val n){
    val sqrtn = sqrt(n);
    for(val i = 2; i <= sqrtn; ++i){
      if(gcd(i, n) != 1)
	return false;
    }
    return true;
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

  vector<val> ModArith::millersFactoring(val a, val N){
    vector<val> ret;
    val g = gcd(a, N);
    std::cout << "a = " << a << "\t";
    if(g > 1){
      ret.push_back(g);
      ret.push_back(N/g);
      std::cout << g << "\t" << N/g;
    }else{
      val s = multOrder(a, N);
      if(s % 2 == 0 && modExp(a, s/2, N) != (val)(N-1)){
        val b = gcd(modExp(a, s/2, N) - 1, N);
        val c = gcd(modExp(a, s/2, N) + 1, N);
        std::cout << b << "\t" << c;
        ret.push_back(b);
        ret.push_back(c);
      }
    }
    std::cout << std::endl;
    return ret;
  }

  val ModArith::multOrder(val a, val N){
    if(a == 0 || a == 1 || N == 0)
      return 1;
    val s = 1;
    while(modExp(a, s, N) != (val)1){
      s++;
    }
    return s;
  }
}
