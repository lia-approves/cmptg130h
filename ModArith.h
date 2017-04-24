#include <bitset>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

using std::ostream; using std::unique_ptr; using std::vector;

namespace CRY{
typedef unsigned long long val;
class ModArith{
 public:
  //Prints primes of the form 2^i + 2^j + 1, where all i < nMax and j < nMax.
  static vector<val> fastPrimes(val nMax);

  //Prints the elements of the group of integers mod n under multiplication, for which all elements have an inverse mod n.
  static vector<val> ZStarGroupElements(val n);

  //Uses the Chinese Remainder Algorithm to find a number v such that v mod n[i] = r[i] for all i.
  static val cra(vector<val> r, vector<val> n);

  //Returns the modular inverse of a, mod n
  static val modInv(val a, val n);

  //Returns a^e mod n
  static val modExp(val a, val e, val n);

  //Returns whether n is prime or not
  static bool isPrime(val n);

  //Returns the value of Euler's totient function for n
  static val totient(val n);

  //Returns the greatest common denominator of a and b
  static val gcd(val a, val b);

};
 template <typename T>
 ostream& operator<<(ostream& os, const vector<T>& v){
   os << "{";
   for(val i = 0; i < v.size() - 1; ++i){
     os << v[i] << ", ";
   }
   if(v.size() != 0){
     os << v[v.size() - 1];
   }
   os << "}";
   return os;
 }
}
