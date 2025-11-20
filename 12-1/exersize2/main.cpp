#include <iostream>
#include <vector>
#include "CMyPoint.h"

using namespace std;

template<typename T>
void printArr(vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); it++) { // 이더레이터
    cout << *it << " ";
  }
  cout << endl;
}

void eg1() {
  vector<CMyPoint> arr;
  for (int i = 0; i < 5; i++) {
    // arr.push_back(CMyPoint(i * 10, i * 10));

    // 객체에서 내부적으로 CMyPoint 생성자를 호출해서 사용. 객체를 직접 생성해서 넣음
    arr.emplace_back(i * 10, i * 10);
    cout << endl << endl;
  }
  cout << "===========" << endl;

  printArr(arr);
}

// 동적할당
void eg2() {
  vector<CMyPoint*> arr;
  arr.push_back(new CMyPoint(10, 10));
  arr.push_back(new CMyPoint(10, 10));
  arr.push_back(new CMyPoint(10, 10));

  for (auto it = arr.begin(); it != arr.end(); it++) { // 이더레이터
    cout << **it << " ";
    delete *it;
  }
}

// smart ptr
void eg3() {
  vector<unique_ptr<CMyPoint>> arr;
  arr.push_back(make_unique<CMyPoint>(10, 10));
  arr.push_back(make_unique<CMyPoint>(10, 10));
  arr.push_back(make_unique<CMyPoint>(10, 10));
  arr.push_back(make_unique<CMyPoint>(10, 10));

  for (auto it = arr.begin(); it != arr.end(); it++) { // 이더레이터
    cout << **it << " ";
  }
}

int main(void) {
  eg1();
  eg2();
  eg3();

  return 0;
}