#include <iostream>
#include <string>
#include <memory>

// 윈도우 전용
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif // !DBG_NEW
#endif

using namespace std;

// 포인터 삭제 함수 정의.
void func_delete(int * ptr) {
  cout << "포인터 삭제" << endl;
  delete ptr;
}

void func_delete_arr(int * ptr) {
  cout << "배열 삭제" << endl;
  delete[] ptr;
}

void ex1() {
  // int *pnum = new int(10);
  unique_ptr<int> pnum = make_unique<int>(10); // 위랑 같음.
  auto pnum2 = make_unique<int>();
  *pnum2 = 123;

  // 객체 직접 생성.
  {
    // 현재 scope {}를 벗어나면 해제됨.
    unique_ptr<int, decltype(&func_delete)> pnum3(new int, &func_delete);
    *pnum3 = 100;
    cout << *pnum3 << endl;
  }

  // unique_ptr<int> pnum2_copy = pnum2; // 불가능.
  unique_ptr<int> pnum2_copy = std::move(pnum2); // pnum2를 nullptr로 만들고 pnum2_copy로 이동
  if (pnum2 == nullptr) {
    cout << "null pointer" << endl;
  } else {
    cout << *pnum2 << endl;
  }
  cout << *pnum2_copy << endl;
}

void ex2() {
  // int *arr = new int[5];
  unique_ptr<int[]> parr = make_unique<int[]>(5);

   {
    // 현재 scope {}를 벗어나면 해제됨.
    unique_ptr<int[], decltype(&func_delete_arr)> pnum3(new int[5], &func_delete);
    pnum3[0] = 100;
    cout << pnum3[0] << endl;
  }

  //  2차원
  // int **parr2 = new int*[5];
  // for (int i = 0; i < 5; i++) {
  //   parr2[i] = new int[3]
  // }
  unique_ptr<unique_ptr<int[]>[]> parr2 = make_unique<unique_ptr<int[]>[]>(5);
  for (int i = 0; i < 5; i++) {
    parr2[i] = make_unique<int[]>(3);
  }

  // auto pstr = new string("Hello");
  auto pstr = make_unique<string>("Hello");
  // string *pstr_c = pstr.get();
  string *pstr_c = pstr.release();
  delete pstr_c;
  pstr_c = nullptr;
}

void ex3() {
  shared_ptr<int> pnum = make_shared<int>(10);
  {
    cout << pnum.use_count() << endl;
    shared_ptr<int> pnum2 = pnum; // 가능.
    cout << pnum.use_count() << endl;
  }
  cout << pnum.use_count() << endl;
}

void ex4() {
  shared_ptr<int[]> parr = make_shared<int[]>(5); // error. compiler version 20부터 가능.
  // 윈도우에서, 프로젝트 => 속성 => C++ 표준. defa
}

int main(void) {
  // 윈도우 전용
  // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  cout << "202112711 이제준" << endl;

  // ex1();
  // ex2();
  // ex3();
  ex4();

  return 0;
}