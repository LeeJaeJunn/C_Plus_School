#include "AdvancedTicket.h"
#include <iostream>

using namespace std;

AdvancedTicket::AdvancedTicket(): AdvancedTicket(0) {}
AdvancedTicket::AdvancedTicket(const double &price, const int &advancedDays)
: Ticket(price), advancedDays(advancedDays) {}
AdvancedTicket::~AdvancedTicket() {}

double AdvancedTicket::getPrice() const {
  return (
    (advancedDays >= 30) ? price * 0.5 :
    (advancedDays >= 20 && advancedDays < 30 ) ? price * 0.7 :
    (advancedDays >= 10 && advancedDays < 20) ? price * 0.9 :
    price
  );
}
int AdvancedTicket::getAdvancedDays() const {
  return advancedDays;
}
void AdvancedTicket::show() const {
  Ticket::show();
  cout << "사전예약일: " << advancedDays << endl;
  cout << "지불금액: " << getPrice() << endl;
}