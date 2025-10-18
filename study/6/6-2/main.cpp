#include <iostream>
#include "Salesman.h"

using namespace std;

// static 변수, static 함수 활용
void eg1() {
  Salesman s1;
  cout << Salesman::getCount() << endl;
  Salesman s2;
  cout << Salesman::getCount() << endl;
  Salesman s3;
  cout << Salesman::getCount() << endl;
  cout << s1.getCount() << endl;
}

int main(void) {
  eg1();

  return 0;
}