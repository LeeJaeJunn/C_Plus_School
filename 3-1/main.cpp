#include <iostream>

#include <crtdbg.h>
// 윈도우 전용
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif // !DBG_NEW
#endif

using namespace std;

void test1() {
  int arr[3][4];
  cout << typeid(arr).name() << endl;
  cout << typeid(arr[0]).name() << endl;
  cout << typeid(arr[0][0]).name() << endl;
}

void test2() {
  int arr[3][4];
  // int[3][4]에 저장된 값은 &int[0] => &int[4]
  int (*parr)[3][4] = &arr; // parr은 int[3][4] 사이즈의 포인터. 따라서 그냥 arrd의 주소를 넘겨주면 됨.
  int (*parr2)[4] = arr; // arr은 층의 시작 주소.int[4] 타입을 arr 이름이 저장하고 있음. 따라서 포인터도 int [4]의 포인터로 선언.

  int *parr3 = arr[0]; // arr[0]은 층에 저장된 값. 방의 시작 주소. arr[0][0]에 해당하는 주소값을 저장.
  // 따라서 &arr[0][0]은 &int 타입.
}

//동적할당
void test3() {
  int (*parr)[4] = new int[3][4];
  int *parr2 = new int[5];
}

// 배열 생성.
int* makeArray(const int SIZE) {
  int *temp = new int[SIZE];
  for (int i = 0; i < SIZE; i ++) {
    temp[i] = rand() % 10;
  }
  return temp;
}
// 그냥 int* 하면 8byte의 크기가 잡힘. & 붙이면 메모리 별도 사용 X.
void printArray(int *(&arr), const size_t SIZE) {
  for (int i = 0; i < SIZE; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
}

int main(void) {
  // 맥에서는 사용불가능.
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  cout << "202112711 이제준" << endl;
  int *arr = makeArray(10);
  printArray(arr, 10);
  
  return 0;
}