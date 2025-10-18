#include <iostream>
#include "Power.h"
// #include "Power.cpp"

using namespace std;

void test1() {
  Power a(3, 5), b(4, 6), c;
  c = a + b;

  a.show();
  b.show();
  c.show();
}

void test2() {
  Power a(5, 6);
  // a << cout;
  cout << a << endl;
}

int main(void) {
  // test1();
  test2();

  return 0;
}