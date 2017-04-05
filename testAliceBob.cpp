#include <iostream>
#include <vector>

#include "modArith.h"

using std::cout; using std::cerr; using std::endl; using std::vector;
using namespace cry;

int main(){
  cout << "19^-1 mod 58 = " << modArith::modInv(19, 58) << endl;
  cout << "25^-1 mod 113 = " << modArith::modInv(25, 113) << endl;
  cout << "totient(248) = " << modArith::totient(248) << endl;
  cout << "23^-1 mod 248 = " << modArith::modInv(23, 248) << endl;
  cout << "23^24 mod 31 = " << modArith::modExp(23, 24, 31) << endl;
  vector<int> r = {0, 4, 2};
  vector<int> n = {5, 7, 9};
  cout << "cra(0, 4, 2; 5, 7, 9) = " << modArith::cra(r, n) << endl;
  r = {2, 1, 1};
  n = {7, 9, 11};
  cout << "cra(2, 1, 1; 7, 9, 11) = " << modArith::cra(r, n) << endl;
  r = {1, 2, 3, 4};
  n = {11, 13, 15, 17};
  cout << "cra(1, 2, 3, 4; 11, 13, 15, 17) = " << modArith::cra(r, n) << endl;
}
