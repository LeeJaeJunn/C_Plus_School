#pragma once
#include "Salesman.h"

class SalesReport {
  private:
    Salesman *team;
    double highestSales;
    double averageSales;
    int number;

  public:
    SalesReport(const int &number);
    ~SalesReport();

    void computeState();
    Salesman getBestClerk();
    string getTeamInfo();

};