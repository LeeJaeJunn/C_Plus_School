#include "Power.h"
#include "iostream"

using namespace std;

void Power::show() {
  cout << this->kick << " " << this->punch << endl;
}

Power Power::operator+(Power op2) {
  Power tmp;
  tmp.kick = this->kick + op2.kick;
  tmp.punch = this->punch + op2.punch;
  return tmp;
}
bool Power::operator==(Power op2) {
  if (this->kick == op2.kick && this->punch == op2.punch) {
    return true;
  } else {
    return false;
  }
  // return (this->kick == op2.kick && this->punch == op2.punch);
}
Power& Power::operator+=(Power op2) {
  this->kick += op2.kick;
  this->punch += op2.punch;
  return *this;
}
Power& Power::operator<<(int n) {
  this->kick += n;
  this->punch += n;
  return *this;
}

Power& Power::operator++() {
  this->kick++;
  this->punch++;
  return *this;
}
Power Power::operator++(int x) {
  Power tmp = *this;
  this->kick++;
  this->punch++;
  return tmp;
}
bool Power::operator!() {
  if (kick == 0 && punch == 0) {
    return true;
  } else {
    return false;
  }
}

// 프렌드
Power operator+(int n, Power op2) {
  Power tmp;
  tmp.kick = n + op2.kick;
  tmp.punch = n + op2.punch;
  return tmp;
}
ostream &operator<<(ostream &out, const Power &p) {
  out << p.kick << " " << p.punch << endl;
  return out;
}
istream &operator>>(istream &in, Power &p) {
  in >> p.kick >> p.punch;
  return in;
}

Power::operator int() {
  return kick + punch;
}
Power& Power::operator()(const int& kick, const int& punch) {
  this->kick = kick;
  this->punch = punch;
  return *this;
}