#pragma once
#include <string>

using std::string;

class Salesman {
  private:
    string m_name;
    double m_sales;
    static inline int count = 0; // c++ 17부터 가능.
    // static int count; 이 경우 Salesman.cpp파일에 전역으로 설정. int Salesman::count = 0

  public:
    Salesman();
    Salesman(const Salesman &man);
    // Salesman(const char *name);
    explicit Salesman(const string &name);
    Salesman(const string &name, const double &sales);
    ~Salesman();

    void setName(const string &name);
    string getName() { // inline 함수.
      return this->m_name;
    } 
    string getName() const { // const는 오버로딩 대상.
      return this->m_name;
    } 

    void setSales(const double &sales);
    double getSales();
    
    void readInput();
    string getSalesmanInfo();

    friend void show(const Salesman &s);
    static int getCount() {
      return count; // this 사용 불가
    }

    void showFriend(Salesman s); // Salesman s = s3 . 복사생성자 호출
};