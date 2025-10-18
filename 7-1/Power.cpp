#include <iostream>
#include "Power.h"

using namespace std;

Power Power::operator+(Power op2) {
  Power tmp;
  tmp.kick = this->kick + op2.kick;
  tmp.punch = this->punch + op2.punch;
  return tmp;
}

Power Power::operator+(int op2) {
  Power tmp; // 임시 객체 생성
  tmp.kick = kick + op2; // kick에 op2 더하기
  tmp.punch = punch + op2; // punch에 op2 더하기
  return tmp; // 임시 객체 리턴
}

bool Power::operator==(Power op2) {
  if (kick == op2.kick && punch == op2.punch) {
    return true;
  } else {
    return false;
  }
}

Power& Power::operator+=(Power op2) {
  kick = kick + op2.kick; // kick 더하기
  punch = punch + op2.punch; // punch 더하기
  return *this; // 합한 결과 리턴
}

Power& Power::operator<<(int n) {
  kick += n;
  punch += n;
  return *this; // 이 객체의 참조 리턴
}

void Power::show() {
  cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}


ostream &operator<<(ostream &out, Power &p) {
  out << p.kick << " " << p.punch << "" << endl;
  return out;
}