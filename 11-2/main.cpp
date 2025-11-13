#include <iostream>
#include <string>
#include "Stack.h"
#include "../11-1/CMyPoint.h"
#include "ArrayData.h"

using namespace std;

void test1() {
  Stack<> stack; // 디폴트 값 int
  stack.push(10);

  Stack<int, 40> istack;
  istack.push(10);
  istack.push(20);
  istack.push(30);
  istack.push(40);
  istack.push(50);
  int item;
  while (istack.pop(item)) {
    cout << item << endl;
  }

  cout << "--------" << endl;

  Stack<double> dstack;
  dstack.push(10.0);
  dstack.push(20.0);
  dstack.push(30.0);
  dstack.push(40.0);
  dstack.push(50.0);
  double ditem;
  while (dstack.pop(ditem)) {
    cout << ditem << endl;
  }

  cout << "--------" << endl;

  Stack<string> sstack;
  sstack.push("jjj1");
  sstack.push("jjj1");
  sstack.push("jjj1");
  string sitem;
  while (sstack.pop(sitem)) {
    cout << sitem << endl;
  }

  cout << "--------" << endl;

  Stack<CMyPoint> ptstack;
  ptstack.push(CMyPoint(10, 20));
  ptstack.push(CMyPoint(10, 20));
  ptstack.push(CMyPoint(10, 20));
  CMyPoint ptitem;
  while (ptstack.pop(ptitem)) {
    cout << ptitem << endl;
  }
}

void test2() {
  ArrayData<CMyPoint> arr1;
  arr1.addElement(CMyPoint(10, 20));
  arr1.addElement(CMyPoint(20, 20));
  arr1.addElement(CMyPoint(30, 20));
  cout << arr1 << endl;

  ArrayData<CMyPoint> arr2 = arr1;
  cout << arr2 << endl;

  ArrayData<CMyPoint> arr3 = move(arr2);
  cout << arr3 << endl;
}

int main(void) {

  // test1();
  test2();

  return 0;
}