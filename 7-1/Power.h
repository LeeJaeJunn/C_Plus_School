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
      Power operator+(Power op2);
      Power operator+(int op2);
      bool operator==(Power op2);
      Power &operator+=(Power op2);
      Power &operator<<(int n);

      void show();

      ostream& operator<<(ostream& out) {
        out << kick << " " << punch << endl;
        return out;
      }

      friend ostream &operator<<(ostream &out, Power &p);
};

ostream &operator<<(ostream &out, Power &p);