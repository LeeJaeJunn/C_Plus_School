// 42
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

void test1() {
  for (size_t i = 1; i <= 1000; i *= 10 ) {
    cout << std::left << std::setfill('_') << std::setw(5) << i << endl;
    cout << std::setfill(' ');
  }
}

void test2() {
  double pi = 3.1415926535;
   
  cout << std::setprecision(4) << pi << endl; // 유효숫자 4개
  cout << std::fixed; // 고정 소수점 자리수
  cout << std::setprecision(4) << pi << endl;
  cout.unsetf(std::ios::fixed);
  cout << std::setprecision(4) << pi << endl;
}

void test3() {
  double d = 10.0;

  cout << d << endl;
  cout << std::showpoint << d << endl;
  cout << std::noshowpoint;
  cout << d << endl;
}

void test4() {
  int num = 10;

  cout << num << endl;
  cout << std::oct << num << endl;
  cout << std::hex << num << endl;
  cout << std::dec;
  cout << num << endl;
}

void ex1() {
  for (size_t i = 1; i < 10; i++) {
    for (size_t j = 1; j < 10; j ++) {
      cout << j << '*' << i << '=' << j * i << '\t';
    }
    cout << endl;
  }
}

int main(void) {

  // ex1();
  // test1();
  // test2();
  // test3();
  test4();

  return 0;
}