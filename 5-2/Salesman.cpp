#include "Salesman.h"
#include <iostream>

using namespace std;

Salesman::Salesman():Salesman("noName", 0.0) {} // 위임 생성자.
Salesman::Salesman(const string &name, const double &sales) 
  : m_name(name), m_sales(sales) {} // initialize 초기화.
Salesman::~Salesman() {
  cout << m_name << "소멸됨" << endl;
}

void Salesman::setName(const string &name) {
  m_name = name;
}
string Salesman::getName() {
  return m_name;
}

void Salesman::setSales(const double &sales) {
  m_sales = sales;
}
double Salesman::getSales() {
  return m_sales;
}

void Salesman::readInput() {
  cout << "이름: ";
  cin >> m_name;
  cout << "실적: ";
  cin >> m_sales;
}
string Salesman::getSalesmanInfo() {
  return "이름: " + m_name + " 판매실적: " + to_string(m_sales);
}