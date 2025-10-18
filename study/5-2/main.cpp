#include <iostream>
#include "SalesReport.h"

using namespace std;

int main(void) {
  SalesReport team1(3);

  team1.computeState();

  cout << team1.getBestClerk().getSalesInfo() << endl;
  cout << team1.getTeamInfo() << endl;

  return 0;
}