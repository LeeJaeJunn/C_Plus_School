#include <iostream>
#include "SalesReport.h"
#include "Salesman.h"

using namespace std;

int main(void) {
  SalesReport team1(5);
  team1.addMember();
  team1.addMember();
  team1.addMember();

  team1.computeState();

  cout << team1.getBestClerk()->getSalesInfo() << endl;
  cout << team1.getTeamInfo() << endl;

  return 0;
}

// salesman을 바꿈. 객체 배열이 아니라 pointer배열.
// slaesman