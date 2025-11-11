#include <iostream>
#include <string>
#include "CMyPoint.h"

using namespace std;

template <typename T>
void print_arr(T *arr, size_t N) {
  for (int i = 0; i < N; i++) {
    cout << arr[i] << endl;
  }
}

template<> // 전문화 함수. 알고리즘이 다른 특별한 타입이 있을 시.
void print_arr(char *arr, size_t N) {
  cout << arr << endl;
}

//reference는 타입, 크기 정보가 정해져 있어야만 받을 수 있음. 따라서 두개의 parameter type 지정
// void show_array(int(&arr)[10]) {} 
template<typename T, size_t N>
void show_array(T(&arr)[N]) {
  for (int i = 0; i < N; i++) {
    cout << arr[i] << endl;
  }
}

template<typename T, size_t N>
void sortAsc(T(&arr)[N]) {
  for (int i = 0; i < N-1; i++) {
    for (int j = i + 1; j < N; j++) {
      if(arr[i] > arr[j]) {
        // swap(arr[i], arr[j]);
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void eg1() {
  int arr1[]{1, 2, 3, 4, 5};
  double arr2[]{1.1, 2.2, 3.3};
  string arr3[]{"greenjoa1", "greenjoa2", "greenjoa2"};

  char arr4[]{'a', 'b', 0, 'c', 'd'};

  // print_arr<int>(arr1, size(arr1));
  // print_arr(arr2, size(arr2));
  // print_arr(arr3, size(arr3));

  // cout << arr1 << endl; // 배열 주소 출력
  // cout << arr4 << endl; // ab 출력. 0을 만날 때까지 출력. null값을 찾아 그 위치를 출력.

  show_array(arr1); // 타입정보, size정보 자동으로 유추
  show_array(arr2);
  show_array(arr3);
}

void eg2() {
  // 연산자 오버로딩 필수.
  CMyPoint arr[]{CMyPoint(100, 100), CMyPoint(50, 30), CMyPoint(150, 200), CMyPoint(80, 40)};

  show_array(arr);
}

void eg3() {
  int arr1[]{1, 5, 3,9, 6};
  double arr2[]{8.1, 5.2, 3.3};
  string arr3[]{"greenjoa8", "greenjoa2", "greenjoa3"};

  sortAsc(arr1);
  show_array(arr1);
  cout << "---------" << endl;
  sortAsc(arr2);
  show_array(arr2);
  cout << "---------" << endl;
  sortAsc(arr3);
  show_array(arr3);
}

void exersize() {
  CMyPoint arr[]{CMyPoint(100, 100), CMyPoint(50, 30), CMyPoint(150, 200), CMyPoint(80, 40)};

  sortAsc(arr);
  show_array(arr);
}

int main(void) {
  // eg1();
  // eg2();
  // eg3();
  exersize();

  return 0;
}