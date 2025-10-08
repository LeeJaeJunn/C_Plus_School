#pragma once
#include "Salesman.h"
#include <memory>
using std::shared_ptr;

class SalesReport {
  private:
    double highestSales;
    double averageSales;
    const int NUMBER;
    // Salesman *team;
    // Salesman **team;
    shared_ptr<shared_ptr<Salesman>[]> team;
    int count = 0;

  public:
    SalesReport(const int number);
    ~SalesReport();

    void addMenber();
    void computeState();
    // Salesman *getBestClerk();
    shared_ptr<Salesman> getBestClerk();
    string getTeamInfo();
};