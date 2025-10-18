#include <iostream>
#include "SalesReport.h"

using namespace std;

SalesReport::SalesReport(const int &number):number(number), team(new Salesman[number]) {
  for (size_t i = 0; i < number; i++) {
    team[i].readInput();
  }
}
SalesReport::~SalesReport() {
  if (!(team == nullptr)) {
    delete[] team;
  }
  team = nullptr;
};

void SalesReport::computeState() {
  if (team == nullptr) {
    cout << "team 정보 없음." << endl;
    return;
  }
  double sum = 0;
  highestSales = 0;
  for (size_t i = 0; i < number; i++) {
    sum += team[i].getSales();
    if (highestSales < team[i].getSales()) {
      highestSales = team[i].getSales();
    }
  }
  averageSales = sum / number;
}
Salesman SalesReport::getBestClerk() {
  int bestidx = 0;
  for (size_t i = 1; i < number; i++) {
    if (team[bestidx].getSales() < team[i].getSales()) {
      bestidx = i;
    }
  }
  return team[bestidx];
}
string SalesReport::getTeamInfo() {
  string info = "안원수: " + to_string(number) + '\n';
  info += "평균 판매량: " + to_string(averageSales) + '\n';
  info += "최고 판매량: " + to_string(highestSales) + '\n';

  return info;
}
