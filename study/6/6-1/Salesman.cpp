#include "Salesman.h"
#include <iostream>

using namespace std;

Salesman::Salesman():Salesman("NoName", 0.0) {}
Salesman::Salesman(const string &name, const double &sales) : name(name), sales(sales) {}
Salesman::~Salesman() {
  cout << "소멸" << endl;
}

void Salesman::setName(const string &name) {
  this->name = name;
}
string Salesman::getName() {
  return name;
}

void Salesman::setSales(const double &sales) {
  this->sales = sales;
}
double Salesman::getSales() {
  return sales;
}

void Salesman::readInput() {
  cout << "이름: ";
  cin >> name;
  cout << "판매실적: ";
  cin >> sales;
}
string Salesman::getSalesInfo() {
  return "이름: " + name + " 판매실적: " + to_string(sales);
}