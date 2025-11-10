#include <iostream>
#include "ArrayDataSmart.h"

using namespace std;

int main(void) {
  ArrayDataSmart arr(5);
  arr.addElement(10.1);
  arr.addElement(10.2);
  arr.addElement(10.3);
  arr.backup();
  arr.addElement(10.4);
  arr.addElement(10.5);
  cout << "arr: " << arr << endl;

  cout << "------ restore -------" << endl;
  arr.restore();
  cout << "arr: " << arr << endl;

  cout << "------ 대입 -------" << endl;
  ArrayDataSmart arr2(2);
  arr2 = arr; // 대입연산자
  cout << "arr2: " << arr2 << endl;

  cout << "------ 이동대입 -------" << endl;
  ArrayDataSmart arr3(3);
  arr3 = move(arr); // 이동대입연산자
  cout << "arr3: " << arr3 << endl;
  

  return 0;
}