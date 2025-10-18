#pragma once
#include <iostream>

using namespace std;

class Power {
  private:
    int kick;
    int punch;

  public:
    Power(int kick = 0, int punch = 0) {
      this->kick = kick;
      this->punch = punch;
    }
    void show();

    // 이항 연산자
    Power operator+(Power op2);
    bool operator==(Power op2);
    Power& operator+=(Power op2);
    Power &operator<<(int n);
    //단항 연산자.
    Power &operator++(); // 전위 연산자
    Power operator++(int x); // 후위 연산자
    bool operator!();
    // 프렌드
    friend Power operator+(int n, Power op2);
    friend ostream &operator<<(ostream &out, const Power &p);
    friend istream &operator>>(istream &in, Power &p);
    // 타입변환
    operator int(); 
    // 함수호출
    Power &operator()(const int &kick, const int &punch);
};
Power operator+(int n, Power op2);
ostream &operator<<(ostream &out, const Power &p);
istream &operator>>(istream &in, Power &p);

// 배열 연산자부터는 6/exersize