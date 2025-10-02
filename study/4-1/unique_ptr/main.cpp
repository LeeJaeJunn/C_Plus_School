#include <iostream>
#include <memory> // smart pointer header file
// unique pointer
using namespace std;

void deleter(int *ptr) {
  cout << "포인터 삭제" << endl;
  delete ptr;
}
void deleter_arr(int *ptr) {
  cout << "배열 삭제" << endl;
  delete[] ptr;
}

// unique pointer
void eg1() {
  unique_ptr<int> pnum = make_unique<int>();
  *pnum = 100;
  // unique_ptr<int> pnum_c = pnum; // 허용 X 다른 포인터로 가리킬 수 없음.
  cout << pnum << '\t' << *pnum << endl;

  unique_ptr<int[]> pnumA = make_unique<int[]>(10);
  for (size_t i = 0; i < 10; i++) {
    pnumA[i] = i + 1;
  }

  for (size_t i = 0; i < 10; i++) {
    cout << pnumA[i] << endl;
  }
}
void eg2() {
  // 객체로 직접 생성.
  unique_ptr<int> pnum(new int);
  *pnum = 1;
  cout << pnum << '\t' << *pnum << endl;

  unique_ptr<int[]> pnumA(new int[5]);
  for (size_t i = 0; i < 5; i++) {
    pnumA[i] = i + 1;
  }
  for (size_t i = 0; i < 5; i++) {
    cout << pnumA[i] << endl;
  }

  unique_ptr<int, decltype(&deleter)> pnum2(new int, &deleter); // deleter 전달.
  *pnum2 = 2;
  cout << *pnum2 << endl;
  unique_ptr<int[], decltype(&deleter_arr)> pnum2A(new int[5], &deleter_arr);
}

void eg3() {
  unique_ptr<int> pnum(new int);
  cout << "pnum변수의 stack 주소:   " << &pnum << endl;
  cout << "pnum의 실제 값 heap 주소:" << pnum << endl;
  cout << "pnum의 실제 값 heap 주소:" << pnum.get() << endl;
  // 최신 컴파일러에서는 그냥 pnum을 써줘도 되지만 함수 인자로 전달시는 pnum.get으로 전달.
}

void eg4() {
  unique_ptr<int> pnum(new int);
  // pnum.reset(); // pnum의 deleter을 호출. 메모리를 해제하고 nullptr로 변환.
  cout << pnum.get() << endl;
  pnum.reset(new int(3)); // 메모리 해제, 새로운 메모리 생성.
  cout << pnum.get() << endl;
}

void eg5() {
  unique_ptr<int> pnum = make_unique<int>(10);

  unique_ptr<int> pnum_copy = std::move(pnum); // 완전한 소유권 이전. 여전히 메모리 자동관리. 기존 pnum은 nullptr
  cout << "pnum: " << pnum << endl;
  cout << "pnum_copy: " << pnum_copy << endl;
  int *pnum_copy2 = pnum_copy.release(); // pnum_copy를 nullptr로 바꾸고 메모리 주소를 이전. 이제 메모리 자동관리 X. delete 해줘야함.
  cout << "pnum_copy: " << pnum_copy << endl;
  cout << "pnum_copy2: " << *pnum_copy2 << endl;
  delete pnum_copy2;
  pnum_copy2 = nullptr;
  cout << "pnum_copy2: " << *pnum_copy2 << endl;
}

// 2차원 배열
void eg6() {
   // int **parr2 = new int*[5];
  // for (int i = 0; i < 5; i++) {
  //   parr2[i] = new int[3]
  // }
  unique_ptr<unique_ptr<int[]>[]> parr = make_unique<unique_ptr<int[]>[]>(3);
  auto parr2 = make_unique<unique_ptr<int[]>[]>(3);
  for (int i = 0; i < 3; i++) {
    parr[i] = make_unique<int[]>(5);
    for (int j = 0; j < 5; j++) {
      parr[i][j] = (i + 1) * 10 + j;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      cout << parr[i][j] << '\t';
    }
    cout << endl;
  }
}

int main(void) {
  // eg1();
  // eg2();
  // eg3();
  // eg4();
  // eg5();
  eg6();

  return 0;
}