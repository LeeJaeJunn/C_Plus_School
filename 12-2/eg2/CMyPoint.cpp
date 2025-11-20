#include "CMyPoint.h"
#include <iostream>

using namespace std;

CMyPoint::CMyPoint() {
  cout << "CMyPoint의 디폴트 생성자" << endl;
}

CMyPoint::~CMyPoint() {
  cout << "CMyPoint의 소멸자" << endl;
}

CMyPoint::CMyPoint(const int &x, const int &y): x(x), y(y) {
  cout << "CMyPoint의 생성자" << endl;
}

CMyPoint::CMyPoint(const CMyPoint &pt): x(pt.x), y(pt.y) {
  cout << "CMyPoint의 복사생성자" << endl;
}

CMyPoint::CMyPoint(CMyPoint &&pt) noexcept: x(pt.x), y(pt.y) {
  cout << "CMyPoint의 이동생성자" << endl;
}

ostream& operator<<(ostream& out, CMyPoint &pt) {
  out << pt.x << ", " << pt.y << endl;
  return out;
};

// bool CMyPoint::operator>(CMyPoint &pt2) {
//   return ((this->x > pt2.x) ? true : false);
// }

bool CMyPoint::operator==(const CMyPoint &pt) const {
  return x == pt.x && y == pt.y;
}