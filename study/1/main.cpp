#include <iostream>

using namespace std;

void areaOfCircle(int r) {
  double pi = 3.14;
  cout << "area of circle: " <<pi * r * r << endl;
}

namespace A_COM {
  void func(void) {
    cout << "A function call" << endl;
  }
  namespace A_TEST {
    void function(void) {
    cout << "A_TTTT" << endl;
  }
  }
}

namespace B_COM {
  void function(void) {
    cout << "B function call" << endl;
  }
}


namespace AA = A_COM::A_TEST;
using namespace std;
using A_COM::func;
int main(void)
{
  func();
  areaOfCircle(3);
  // AA::function();
  B_COM::function();

  return 0;
}