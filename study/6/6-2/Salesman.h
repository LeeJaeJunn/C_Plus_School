#pragma once
#include <string>

using std::string;

class Salesman {
  private:
    string name;
    double sales;
    friend class B; // class B에서 Salesman 모두 접근가능
    static inline int count = 0;

  public:
    Salesman();
    Salesman(const string &name, const double &sales);
    ~Salesman();

    void setName(const string &name);
    string getName() {
      return this->name; // 인라인 함수.
    }
    string getName() const {
      return this->name; // const로 선언된 클래스에서 접근 가능
    }

    void setSales(const double &name);
    double getSales() {
      return this->sales;
    }
    double getSales() const {
      return this->sales;
    }

    void readInput();
    string getSalesInfo();

    static int getCount() {
      return count; // static 함수에서는 this 불가능
    }
};