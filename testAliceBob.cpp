#include <iostream>
#include <vector>

#include "ModArith.h"

using std::cout; using std::cerr; using std::endl; using std::vector;
using namespace CRY;

int main(){
  cout << "19^-1 mod 58 = " << ModArith::modInv(19, 58) << endl;
  cout << "25^-1 mod 113 = " << ModArith::modInv(25, 113) << endl;
  cout << "totient(248) = " << ModArith::totient(248) << endl;
  cout << "23^-1 mod 248 = " << ModArith::modInv(23, 248) << endl;
  cout << "23^24 mod 31 = " << ModArith::modExp(23, 24, 31) << endl;
  vector<val> r = {0, 4, 2};
  vector<val> n = {5, 7, 9};
  cout << "cra(0, 4, 2; 5, 7, 9) = " << ModArith::cra(r, n) << endl;
  r = {2, 1, 1};
  n = {7, 9, 11};
  cout << "cra(2, 1, 1; 7, 9, 11) = " << ModArith::cra(r, n) << endl;
  r = {1, 2, 3, 4};
  n = {11, 13, 15, 17};
  cout << "cra(1, 2, 3, 4; 11, 13, 15, 17) = " << ModArith::cra(r, n) << endl;
  
  cout << "Z*5, * mod 5 = " << ModArith::ZStarGroupElements(5) << endl;
  
  cout << "Fast primes of the form 2^i + 2^j + 1, where i and j < 30 : " << ModArith::fastPrimes(30) << endl;

}
