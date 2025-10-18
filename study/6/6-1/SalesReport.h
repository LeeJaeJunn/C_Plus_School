#pragma once
#include <memory>
#include "Salesman.h"

class SalesReport {
  private:
    // Salesman *team;
    // Salesman **team;
    shared_ptr<shared_ptr<Salesman>[]> team;
    
    double highestSales;
    double averageSales;
    int number;
    int count = 0;

  public:
    SalesReport(const int &number);
    ~SalesReport();

    void computeState();
    shared_ptr<Salesman> getBestClerk();
    string getTeamInfo();

    void addMember();
};