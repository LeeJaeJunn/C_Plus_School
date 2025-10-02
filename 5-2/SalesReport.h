#pragma once
#include "Salesman.h"

class SalesReport {
  private:
    double highestSales;
    double averageSales;
    const int NUMBER;
    Salesman *team;

  public:
    SalesReport(const int number);
    ~SalesReport();

    void computeState();
    Salesman &getBestClerk();
    string getTeamInfo();
};