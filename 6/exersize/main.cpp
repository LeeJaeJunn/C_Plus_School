#include <iostream>
#include "ArrayData.h"

using namespace std;

// void showArray(ArrayData arr1) {
//   arr1.showData();
// }

void showArray(ArrayData &arr1) {
  arr1.showData();
}

ArrayData getArr(const int& num) {
  // ArrayData arr(num);
  // return arr;

  return ArrayData(num);
}

int main(void) {
  ArrayData data1;
  data1.addElement(5.5);
  data1.addElement(5.5);
  data1.addElement(5.5);
  data1.showData();
  cout << "===========" << endl;
  ArrayData copy1(data1);
  // copy1.showData();
  showArray(copy1);
  cout << "===========" << endl;
  ArrayData copy2 = getArr(10);

  return 0;
}