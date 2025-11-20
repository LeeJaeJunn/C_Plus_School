#pragma once
#include <iostream>

using namespace std;

class CMyPoint {
  private:
    int x, y;

  public:
    CMyPoint();
    ~CMyPoint();
    CMyPoint(const int &x, const int &y);
    CMyPoint(const CMyPoint &pt);
    CMyPoint(CMyPoint &&pt) noexcept; //  이거 안만들 시 복사생성자 호출. 효율 떨어짐.
    // 

    friend ostream& operator<<(ostream& out, CMyPoint &pt); // 안해줄 시 error 연산자 오버로딩 필수
    // bool operator>(CMyPoint &pt);
    bool operator==(const CMyPoint &pt) const;
};

ostream& operator<<(ostream& out, CMyPoint &pt);
