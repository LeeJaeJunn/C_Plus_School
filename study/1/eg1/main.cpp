// 38
#include <iostream>
#include "header/gdhongNS.h"

using gdhongNS::showName;
using std::cout;
using std::endl;

namespace gdgoNS {
  void showName() {
    cout << "고길동" << endl;
  }
}

int main(void)
{
  cout << "202112711 이제준" << endl;
  showName();
  gdgoNS::showName();

  return 0;
}