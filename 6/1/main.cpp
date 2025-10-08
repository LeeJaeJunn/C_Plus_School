#include <iostream>
#include "Salesman.h"
// #include "Salesman.cpp" // 난 왜 이거 해야지 실행되냐
#include "SalesReport.h"
// #include "Salesman.cpp"

using namespace std;

int main(void) {
  cout << "202112711 이제준" << endl;

  SalesReport team(5);
  team.addMenber();
  team.addMenber();
  team.addMenber();
  
  team.computeState();

  cout << team.getTeamInfo() << endl;
  cout << team.getBestClerk()->getSalesmanInfo() << endl;

  return 0;
}