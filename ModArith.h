#include <bitset>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

using std::unique_ptr; using std::vector;

namespace CRY{
typedef unsigned long long val;
class ModArith{
 public:
  static vector<val> ZStarGroupElements(val n);
  static val cra(vector<val> r, vector<val> n);
  static val modInv(val a, val n);
  static val modExp(val a, val e, val n);
  static bool isPrime(val n);
  static val totient(val n);
  static val gcd(val a, val b);
};
}
