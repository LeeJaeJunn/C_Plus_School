// Reference 20p~
#include <iostream>

using namespace std;

void test1() {
  int num = 100;
  int &num2 = num;
  int &num3 = num2;
  num3 = 110;

  cout << num << endl; // 110
}

void test2() {
  int num = 10;
  int *ptr = &num;
  int **dptr = &ptr;

  int &ref = num;
  int *(&pref) = ptr;
  int **(&dpref) = dptr;

  cout << ref << endl; // 10
  cout << *pref << endl; // 10
  cout << **dpref << endl; // 10
}

void test3() {
  int arr[3] = {10, 20, 30};
  int (&ref)[3] = arr;
  for (auto i : ref) {
    cout << i << '\t';
  }
  cout << endl;

  ref[0] = 11;
  for (auto i : arr) {
    cout << i << '\t';
  }
  cout << endl;

  cout << "==========" << endl;

  int arr2[2][3] = {
    {1, 2, 3},
    {10, 11, 12}
  };
  int (&ref2)[2][3] = arr2;

  for (auto &i: arr2) {
    for (auto j : i) {
      cout << j << '\t';
    }
    cout << endl;
  }
  ref2[0][1] = 21;
  for (auto &i: arr2) {
    for (auto j : i) {
      cout << j << '\t';
    }
    cout << endl;
  }
}

int main(void) {
  // test1();
  // test2();
  test3();

  return 0;
}