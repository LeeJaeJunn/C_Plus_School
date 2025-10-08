#include <iostream>
#include "Salesman.h"
using namespace std;

void show(const Salesman& s) {
  // cout << s.getName() << endl;
  cout << s.m_name << endl; // 헤더에 friend를 사용. private 멤버 접근 가능
}

void ex1() {
  cout << Salesman::getCount() << endl;
  Salesman s1("jjjjun", 200.0);
  // show(s1);
  Salesman s2("jjjjun2", 200.0);
  Salesman *s3 = new Salesman();
  cout << Salesman::getCount() << endl;
  delete s3;
  cout << Salesman::getCount() << endl;
}

void ex2() {
  Salesman s1;
  Salesman s2("jjjjun");
  Salesman s3("jjjjun", 200.0);

  Salesman s4 = s3; // 복사생성자. compiler가 직접 default compiler를 만들어줌
  Salesman s5(s4); // 복사생성자

  // Salesman s6 = "jjjjj"s; // 묵시적 형변환. explicit을 생성자에 붙여서 대입연산으로 불가능.

  auto str = "ljjjjjun"s; // 뒤에 s붙이면 string으로 바꿔줌.
  cout << typeid(str).name() << endl;

  cout << s4.getSalesmanInfo() << endl;
}

Salesman getSalesman(const string &name) {
  Salesman s(name);
  return s;
}

Salesman getSalesman2(const string &name) {
  return Salesman(name);
}

void ex3() {
  Salesman s1;
  Salesman s2("jjjjun");
  Salesman s3("jjjjun", 200.0);

  Salesman copy1(s2);
  Salesman copy2 = s3;

  cout << copy1.getSalesmanInfo() << endl;
  cout << copy2.getSalesmanInfo() << endl;

  Salesman copy3 = Salesman("RKRKRKRk"); // 오른쪽은 임시객체. 이 경우 복사생성자 호출 X. 컴파일러가 최적화 작업 수행.

  cout << "==============" << endl;
  copy3.showFriend(s3); // 복사 생성자 호출
  cout << "==============" << endl;
  Salesman s4 = getSalesman("asdasd"); // s 수업에선 복사생성자 호출된다 함. 난 안됨.
  cout << "==============" << endl;
  Salesman s5 = getSalesman2("asdasdㅁㄴㅇㅁㄴㅇ"); // Salesman(name)  복사생성자 호출 x
}

int main(void) {
  // ex1();
  // ex2();
  ex3();

  return 0;
}