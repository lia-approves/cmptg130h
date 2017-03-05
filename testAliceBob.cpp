#include <iostream>
#include "modArith.h"

using std::cout; using std::cerr; using std::endl;
using namespace cry;

int main(){
  cout << "19^-1 mod 58 = " << modArith::modInv(19, 58) << endl;
  cout << "25^-1 mod 113 = " << modArith::modInv(25, 113) << endl;
  cout << "totient(248) = " << modArith::totient(248) << endl;
  cout << "23^-1 mod 248 = " << modArith::modInv(23, 248) << endl;
  cout << "23^24 mod 31 = " << modArith::modExp(23, 24, 31) << endl;
}
