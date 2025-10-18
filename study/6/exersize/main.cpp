#include <iostream>
#include "ArrayData.h"

using namespace std;

void showArr(const ArrayData& arr1) {
  arr1.showData();
}

ArrayData getArr(const int &num) {
  ArrayData arr(num);
  return arr;
}

void eg1() {
  ArrayData data1;
  data1.addElement(5.5);
  data1.addElement(5.5);
  data1.addElement(5.5);
  data1.addElement(5.5);
  data1.addElement(5.5);
  data1.addElement(5.5);
  data1.addElement(5.5);
  data1.showData();
  showArr(data1);

  ArrayData *parr = new ArrayData(10);
  parr->addElement(10.5);
  parr->addElement(10.5);
  parr->addElement(10.5);
  parr->showData();

  delete parr;
}

int main(void) {

  // showArr(getArr(10));
  ArrayData arr1(5);
  arr1.addElement(10.5);
  arr1.addElement(10.6);
  
  arr1.showData();
  cout << arr1[1] << endl;
  arr1[3] = 123.01;
  cout << arr1[3] << endl;

  return 0;
}