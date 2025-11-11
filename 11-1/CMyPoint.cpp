#include "CMyPoint.h"
#include <iostream>

using namespace std;

CMyPoint::CMyPoint(const int &x, const int &y): x(x), y(y) {}

bool CMyPoint::operator>(CMyPoint &pt2) {
  return ((this->x > pt2.x) ? true : false);
}

ostream& operator<<(ostream& out, CMyPoint &pt) {
  out << pt.x << ", " << pt.y << endl;
  return out;
};