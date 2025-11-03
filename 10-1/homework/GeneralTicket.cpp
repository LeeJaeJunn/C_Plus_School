#include "GeneralTicket.h"
#include <iostream>

using namespace std;

GeneralTicket::GeneralTicket(): GeneralTicket(0.0) {}
GeneralTicket::GeneralTicket(const double &price, const bool &payByCredit)
: payByCredit(payByCredit), Ticket(price)
{}
GeneralTicket::~GeneralTicket() {}

double GeneralTicket::getPrice() const {
  return price;
}
bool GeneralTicket::getPayByCredit() const {
  return payByCredit;
}
void GeneralTicket::show() const {
  Ticket::show();
  cout << "카드결제여부: " << (payByCredit ? "true" : "false") << endl;
  cout << "지불금액: " << (payByCredit ? price * 1.1 : price) << endl;
}