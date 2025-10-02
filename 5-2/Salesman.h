#pragma once
#include <string>

using std::string;

class Salesman {
  private:
    string m_name;
    double m_sales;
  
  public:
    Salesman();
    Salesman(const string &name, const double &sales);
    ~Salesman();

    void setName(const string &name);
    string getName();

    void setSales(const double &sales);
    double getSales();
    
    void readInput();
    string getSalesmanInfo();
};