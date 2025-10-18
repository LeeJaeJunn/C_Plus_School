#include <iostream>
// #include "Circle.h"
#include "Circle.cpp"

using namespace std;

int main(void) {
  Circle donut;
  donut.radius = 2;
  cout << donut.getArea() << endl;

  return 0;
}