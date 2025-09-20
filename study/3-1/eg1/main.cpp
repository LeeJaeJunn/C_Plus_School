#include <iostream>
#include <string>

using namespace std;

// 1차원 배열 개념 복습...
void test1() {
  int arr[3] = {0, 1, 2};
  cout << *(arr+1)  << '\t' << arr[0] << '\t' << arr[1] <<endl;

  int *ptr = arr;
  cout << ptr << '\t' << *ptr << '\t' << ptr[1] << *(ptr + 2)<< ptr[3]<<  endl;
}
// 2차원 배열 개념 복습...
void test2() {
  int arr[3][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {10, 11, 12, 13}};

  // cout << (*(arr + 1)) << '\t' << *arr[1] << '\t' << **arr << endl; // *arr[1]은 arr[1]에 접근. (*arr)[1]은 arr[0]에 접근 후 [1].

  // cout << (*arr + 1)[1] << endl; // 이건 arr[0][2]. *arr에 +1을 하는 순간 int[4] 타입이 아니라 int*타입으로 바뀜.
  cout << **(arr) << endl;
  cout << *(arr[0] + 1) << endl;
  cout << *(*(arr + 2) + 1) << endl;
}

void test3() {
  int arr[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {10, 11, 12, 13}
  };
  int (*parr1)[4] = arr; // arr의 타입은 int[3][4]. dptr의 타입은 int[4]의 주소값들. (둘다 int(*)[4])
  int (*parr2)[3][4] = &arr; // arr의 타입은 int(*)[4]. &arr은 int(*)[3][4]
  int *parr3 = arr[0]; // arr[0]의 타입은 int[4].
  // int *parr[3]; // int *을 저장하는 배열. (int type adress 3개 저장)
  // int (*parr)[3]; // int[3]을 가리키는 pointer

  // 동적 할당.
  int (*parr4)[4] = new int[3][4];
  // int **parr4 = new int[3][4]; // 안됨. 층을 건너뛰지 못함. int[3][3]은 층을 int[3]만큼 건너뛰는데 pointer은 모름
  int *parr5 = new int;
  int *parr6 = new int[3];
}

void test4() {
  int *pi = new int;
  *pi = 200;
  cout << "adress: " << pi << " value: " << *pi << endl;
  delete pi;
  pi = nullptr;
}

void test5() {
  int *pi = new int[3];
  pi[0] = 100;
  pi[1] = 200;
  pi[2] = 300;
  for (size_t i = 0; i < 3; i++) {
    cout << pi[i] << endl;
  }
  delete[] pi;
  pi = nullptr;
}

// 2차원 배열 동적 할당.
void test6() {
  int **arr = new int *[5];
  for (int i = 0; i < 5; i++) {
    arr[i] = new int[3]; // [5][3] 배열
    // 이제 여기서 각 행마다 데이터 삽입
  }

  for (int i = 0; i < 5; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}

int main(void) {
  // test1();
  // test2();
  // test3();

  string a = "123";
  // int b = static_cast<int>(a);

  return 0;
}