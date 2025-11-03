#include "Ticket.h"
#include <iostream>

using namespace std;

Ticket::Ticket():Ticket(0.0) {}
Ticket::Ticket(const double &price): number(count++), price(price) {}
// Ticket::Ticket(const int &number, const double &price) {
//   if (number <= count ) {
//     cout << "중복된 티켓입니다" << endl;
//     return;
//   }
//   this->number = number;
//   this->price = price;
// }
Ticket::~Ticket() {}

int Ticket::getNumber() const {
  return number;
}
double Ticket::getPrice() const {
  return price;
}
void Ticket::setPrice(const double &price) {
  this->price = price;
}
void Ticket::show() const {
  cout << "티켓번호: " << number << endl;
  cout << "가격정보: " << price << endl;
}