#include "SalesReport.h"
#include <iostream>

using namespace std;

SalesReport::SalesReport(const int number)
  :NUMBER(number),averageSales(0.0), highestSales(0.0), 
  // team(new Salesman*[NUMBER]) 
  team(make_shared<shared_ptr<Salesman>[]>(NUMBER))
{
  if (NUMBER > 0) {
    cout << "팀 생성 완료" << endl;
  } else {
    team = nullptr;
  }
}
SalesReport::~SalesReport() {
  // if (team != nullptr) {
  //   for (int i = 0; i < count; i++) {
  //     delete team[i];
  //   }
  //   delete[] team;
  // }
  // team = nullptr;
}

void SalesReport:: addMenber() {
  if (count >= NUMBER) {
    cout << "더이상 추가할 수 없음" << endl;
    return;
  }

  // team[count] = new Salesman();
  team[count] = make_shared<Salesman>();
  team[count]->readInput();
  count++;
  // string name;
  // double sales;
  // cout << "이름: ";
  // cin >> name;
  // cout << "실적: ";
  // cin >> sales;

  // team[count++] = new Salesman(name, sales);
  // team[count++] = make_shared<Salesman>(name, sales);
}

void SalesReport::computeState() {
  if (team != nullptr) {
    double sum = team[0]->getSales();
    highestSales = team[0]->getSales();
    for (int i = 0; i < count; i++) {
      if (highestSales < team[i]->getSales()) {
        highestSales = team[i]->getSales();
      }
      sum += team[i]->getSales();
    }
    averageSales = sum / count;
  }
}
shared_ptr<Salesman> SalesReport::getBestClerk() {
  int bestIdx = 0;
  for (int i = 1; i < count; i++) {
    if (team[bestIdx]->getSales() < team[i]->getSales()) {
      bestIdx = i;
    }
  }
  return team[bestIdx];
}
string SalesReport::getTeamInfo() {
  string info = "인원수" + to_string(count) + '\n';
  info += "평균 판매랑: " + to_string(averageSales) + '\n';
  info += "최고 판매랑: " + to_string(highestSales) + '\n';
  return info;
}