#include <iostream>

using namespace std;

void eg1() {
  shared_ptr<int> pnum = make_shared<int>(3);

  weak_ptr<int> pnum_copy(pnum);
  cout << pnum.use_count() << endl;
  {
    auto pnum_copy2 = pnum_copy.lock(); // weak_ptr이 참조하는 share_ptr 타입 반환
    cout << pnum.use_count() << endl;
    *pnum_copy2 = 10;
  }
  cout << *pnum << endl;
  cout << pnum.use_count() << endl;
}

void eg2_2(weak_ptr<int> &weakstr) {
  auto resourse = weakstr.lock();
  if (resourse) {
    cout << *resourse << '\t' << resourse.use_count() << endl;
  } else {
    cout << resourse << '\t' << resourse.use_count() << endl;
    cout << "값 없음" << endl;
  }
}
void eg2() {
  shared_ptr<int> pnum = make_shared<int>(3);
  weak_ptr<int> pnum_copy = pnum;

  cout << "===1111111===" << endl;
  eg2_2(pnum_copy);
  pnum.reset();
  cout << "===2222222===" << endl;
  eg2_2(pnum_copy);
}


int main(void) {
  // eg1();
  eg2();

  return 0;
}