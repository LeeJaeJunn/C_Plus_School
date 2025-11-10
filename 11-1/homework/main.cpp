#include <iostream>
#include "Ticket.h"
#include "GeneralTicket.h"
#include "AdvancedTicket.h"
#include "TicketManager.h"

using namespace std;

int main(void) {
  TicketManager manager("아이유콘서트", 10);

  manager.buy(new AdvancedTicket(1000, 40));
  manager.buy(new AdvancedTicket(1500, 30));
  manager.buy(new AdvancedTicket(2000, 25));
  manager.buy(new AdvancedTicket(1000, 5));
  manager.buy(new GeneralTicket(2000, true));
  manager.buy(new GeneralTicket(1500, false));

  cout << manager << endl;

  manager.showGeneralTicket(true);
  manager.showGeneralTicket(false);
  manager.showAdvancedTicket();

  return 0;
}