#include <iostream>
#include "Power.h"

using namespace std;

int main(void) {
  Power p1(10, 10);
  Power p2(20, 20);
  Power p4(20, 20);

  Power p3 = p1 + p2;
  // ++p1;
  // p1.show();
  // (p1++).show();
  // p1.show();
  // p4 << 3 << 2;
  // p4.show();

  // cout << (p2 == p1) << endl;

  // p3.show();
  // cout << p1;
  // Power p5 = 3 + p1;
  // cin >> p1;
  // p1.show();
  // int power = p1;
  // cout << power;

  Power b = p1(20, 30);
  b.show();
  p1.show();

  return 0;
}
