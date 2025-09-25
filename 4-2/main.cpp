#include <iostream>

using namespace std;

void ex1() {
  shared_ptr<int> pnum1 = make_shared<int>(10);
  auto pnum1_c = pnum1;

  cout << pnum1.use_count() << endl;
  cout << *pnum1_c << endl;

  pnum1.reset();

  cout << *pnum1_c << endl; // 출력됨. heap 영역에 pnum1_c 가 있어서 count가 1
}

void ex2() {
  shared_ptr<int> pnum1 = make_shared<int>(10);
  // weak_ptr<int> pnum1_w = pnum1;
  weak_ptr<int> pnum1_w(pnum1); // count 증가 X
  cout << pnum1.use_count() << endl; // 1
  {
    auto pnum1_s = pnum1_w.lock(); // weak_ptr이 참조하는 shared_ptr을 반환.
    if (pnum1_s) {
      cout << *pnum1_s << endl;
    } else {
      cout << "리소스 없음" << endl;
    }
  }

  pnum1.reset();

  auto pnum1_s2 = pnum1_w.lock(); // lock은 shared_ptr를 반환. 따라서 heap영역 지워지지 않음.
  if (pnum1_s2) {
    cout << *pnum1_s2 << endl;
  } else {
    cout << "리소스 없음" << endl;
  }
}

int main(void) {
  cout << "202112711 이제준" << endl;

  // ex1();
  ex2();

  return 0;
}