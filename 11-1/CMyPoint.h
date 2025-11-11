#pragma once
#include <iostream>

using namespace std;

class CMyPoint {
  private:
    int x, y;

  public:
    CMyPoint() = default;
    ~CMyPoint() = default;
    CMyPoint(const int &x, const int &y);

    friend ostream& operator<<(ostream& out, CMyPoint &pt); // 안해줄 시 error 연산자 오버로딩 필수
    bool operator>(CMyPoint &pt);
};

// ostream& operator<<(ostream& out, CMyPoint &pt);
