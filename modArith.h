#include <bitset>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;

namespace cry{
class modArith{
 public:
  static unsigned long cra(vector<int> r, vector<int> n);
  static unsigned long modInv(int a, int n);
  static unsigned long modExp(int a, int e, int n);
  static unsigned long totient(int n);
  static unsigned long gcd(int a, int b);
};
}

