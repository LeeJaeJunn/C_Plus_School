#include <iostream>
#include "Salesman.h"
// #include "Salesman.cpp" // 난 왜 이거 해야지 실행되냐
#include "SalesReport.h"
// #include "Salesman.cpp"

using namespace std;

int main(void) {
  cout << "202112711 이제준" << endl;

  SalesReport team1(3);
  team1.computeState();

  cout << team1.getTeamInfo() << endl;
  cout << team1.getBestClerk().getSalesmanInfo() << endl;

  // Salesman man1;
  // Salesman *man2 = new Salesman();

  // delete man2;
  // Salesman man3("홍길동", 200.0);

  // cout << man3.getSalesmanInfo() << endl;
  return 0;
}