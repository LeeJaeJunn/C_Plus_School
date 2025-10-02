#include <iostream>
#include <memory>
// shared pointer
using namespace std;

void eg1() {
  // object 생성
  shared_ptr<int> num(new int);

  // make_shared 함수 c++20 이상부터 사용가능
  shared_ptr<int> pnum = make_shared<int>(10);
  cout << *pnum << endl;
  cout << "count: " << pnum.use_count() << endl;

  shared_ptr<int> pnum_copy = pnum;
  cout << *pnum_copy << endl;
  cout << "count: " << pnum.use_count() << endl;
  *pnum_copy = 100;
  cout << *pnum << endl;
  cout << *pnum_copy << endl;
}

void eg2() {
  shared_ptr<int[]> parr = make_shared<int[]>(3);
  cout << parr.use_count() << endl;

  {
    shared_ptr<int[]> parr2 = parr;
    cout << parr.use_count() << endl;
  }
  cout << parr.use_count() << endl;
}

int main(void) {
  // eg1();
  eg2();

  return 0;
}