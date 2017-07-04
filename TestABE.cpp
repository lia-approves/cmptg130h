#include <iostream>
#include <vector>

#include "DiffieHellman.h"
#include "ModArith.h"

using std::cout; using std::cerr; using std::endl;
using namespace CRY;

int main(){
  cout << DiffieHellman::maxUInt() << endl;
  cout << DiffieHellman::maxULong() << endl;
  cout << DiffieHellman::maxULongLong() << endl;
  return 0;
}
