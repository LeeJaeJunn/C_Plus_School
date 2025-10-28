#include <iostream>
#include "SalesReport.h"

using namespace std;

SalesReport::SalesReport(const int &number)
  :number(number), averageSales(0.0), highestSales(0.0),
  // team(new Salesman*[number]) // 포인터 배열
  team(make_shared<shared_ptr<Salesman>[]>(number)) 
{
  cout << "팀 생성 완료" << endl; 
}
SalesReport::~SalesReport() {
  // if (!(team == nullptr)) {
  //   for (size_t i = 0; i < count; i++) {
  //     delete team[i];
  //   }
  //   delete[] team;
  // }
  // team = nullptr;
};

void SalesReport::computeState() {
  if (team == nullptr) {
    cout << "team 정보 없음." << endl;
    return;
  }
  double sum = 0;
  highestSales = 0;
  for (size_t i = 0; i < count; i++) {
    sum += team[i]->getSales();
    if (highestSales < team[i]->getSales()) {
      highestSales = team[i]->getSales();
    }
  }
  averageSales = sum / count;
}
shared_ptr<Salesman> SalesReport::getBestClerk() {
  int bestidx = 0;
  for (size_t i = 1; i < count; i++) {
    if (team[bestidx]->getSales() < team[i]->getSales()) {
      bestidx = i;
    }
  }
  return team[bestidx];
}
string SalesReport::getTeamInfo() {
  string info = "안원수: " + to_string(count) + '\n';
  info += "평균 판매량: " + to_string(averageSales) + '\n';
  info += "최고 판매량: " + to_string(highestSales) + '\n';

  return info;
}

void SalesReport::addMember() {
  if (count >= number) {
    cout << "더이상 추가 못ㅎ" << endl;
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