// 2. 35p
#include <iostream>

using namespace std;

// symbolic constant (기호상수) 2가지.
void test1() {
  const int MONTH = 12; // const. runtime constant. compile시 값이 정해져 있지 않아도 됨.
  double m_salary, y_salary;
  cout << "월급 입력: ";
  cin >> m_salary;
  y_salary = 12 * m_salary;
  cout << "연봉 " << y_salary << endl;
}
void test2() {
  constexpr int arr[3] = {1, 2, 3}; // constexpr. compile-time constant. compile시 초기값 정해져 있어야 함. 주로 배열에 사용
  for (auto i: arr) {
    cout << i << '\t';
  }
  cout << endl;
}
void test3() {
  int a, b;
  a = (b = 3, b + 2); // 여러개일 경우 가장 오른쪽의 표현식만 고려.
  cout << a << '\t' << b << endl;
}

int main(void) {
  // test1();
  // test2();
  test3();

  return 0;
}