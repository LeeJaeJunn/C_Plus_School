#pragma once
#include <string>

using std::string;

class Salesman {
  private:
    string name;
    double sales;

  public:
    Salesman();
    Salesman(const string &name, const double &sales);
    ~Salesman();

    void setName(const string &name);
    string getName();

    void setSales(const double &name);
    double getSales();

    void readInput();
    string getSalesInfo();
};