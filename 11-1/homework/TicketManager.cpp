#include "TicketManager.h"
#include "AdvancedTicket.h"
#include "GeneralTicket.h"

TicketManager::TicketManager(const string &name, const int &number)
: m_name(name), totalNumber(number), ticket(new Ticket*[totalNumber]) {}
TicketManager::~TicketManager() {
  for (int i = 0; i < count; i++) {
    delete ticket[i];
  }
  delete[] ticket;
}
void TicketManager::buy(Ticket *t) {
  ticket[count++] = t;
}
void TicketManager::show() const {
  int price = 0;
  cout << "총 예약 매수: " << count << endl;
  cout << "--------------" << endl;
  for (int i = 0; i < count; i++) {
    ticket[i]->show();
    price += ticket[i]->getPrice();
    cout << endl;
  }
  cout << "--------------" << endl;
  cout << "총 예약 금액: " << price << endl;
  cout << "--------------" << endl;
}
void TicketManager::showGeneralTicket(const bool &card) {
  int price = 0;
  cout << "------- 일반 예약 현황 ------" << endl;
  cout << "카드결제여부: " << (card ? "true" : "false") << endl;
  for (int i = 0; i < count; i++) {
    GeneralTicket *generalTicket = dynamic_cast<GeneralTicket*>(ticket[i]);
    if (generalTicket != nullptr) {
      if (generalTicket->getPayByCredit() == card) {
        price += generalTicket->getPrice();
        cout << "--------------" << endl;
        generalTicket->show();
        cout << endl;
        cout << "--------------" << endl;
      }
    }
  }
  cout << "--------------" << endl;
  cout << "총 예약 금액: " << price << endl;
  cout << "--------------" << endl;
}
void TicketManager::showAdvancedTicket() {
  int price = 0;
  cout << "------- 사전 예약 현황 ------" << endl;
  for (int i = 0; i < count; i++) {
    AdvancedTicket *advancedTicket = dynamic_cast<AdvancedTicket*>(ticket[i]);
    if (advancedTicket != nullptr) {
      price += advancedTicket->getPrice();
      advancedTicket->show();
      cout << endl;
    }
  }
  cout << "--------------" << endl;
  cout << "총 예약 금액: " << price << endl;
  cout << "--------------" << endl;
}

// 이부분 수정하자.
ostream &operator<<(ostream &out, const TicketManager &manager) {
  int price = 0;
  out << "총 예약 매수: " << manager.count << endl;
  out << "--------------" << endl;
  for (int i = 0; i < manager.count; i++) {
    manager.ticket[i]->show();
    price += manager.ticket[i]->getPrice();
    out << endl;
  }
  out << "--------------" << endl;
  out << "총 예약 금액: " << price << endl;
  out << "--------------" << endl;
  return out;
}
