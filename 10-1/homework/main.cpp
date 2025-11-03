#include <iostream>
#include "Ticket.h"
#include "GeneralTicket.h"
#include "AdvancedTicket.h"

using namespace std;

int main(void) {
  Ticket ticket(1000.0);
  ticket.show();
  cout << "---------------" << endl;

  AdvancedTicket aticekt(1000.0, 20);
  aticekt.show();
  cout << "---------------" << endl;

  GeneralTicket gticket(2000.0, true);
  gticket.show();

  return 0;
}