#include <iostream>
#include "ArrayData.h"
#include <vector>

using namespace std;

void showArr(ArrayData &arr1) {
  cout << __FUNCTION__ << "(&)" << endl;
  arr1.showData();
}

void showArr(ArrayData &&arr1) {
  cout << __FUNCTION__ << "(&&)" << endl;
  arr1.showData();
}

ArrayData getArr(const int& num) {
  ArrayData arr(num);
  return arr;

  // return ArrayData(num);
}

int main(void) {
  // showArr(getArr(10)); // getArr은 r-value data. 임시객체

  vector<ArrayData> vec;
  for (size_t i = 0; i < 4; i++) {
    cout << "iteration" << i << endl;
    vec.push_back(ArrayData(5));
    cout << endl;
  }

  return 0;
}