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

int main(void) {
  vector<CMyPoint> arr;
  for (int i = 0; i < 5; i++) {
    // arr.push_back(CMyPoint(i * 10, i * 10));

    // 객체에서 내부적으로 CMyPoint 생성자를 호출해서 사용
    arr.emplace_back(i * 10, i * 10);
    cout << endl << endl;
  }
  cout << "===========" << endl;

  printArr(arr);

  return 0;
}