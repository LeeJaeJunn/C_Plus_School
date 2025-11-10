#pragma once
#include <string>
#include <iostream>
#include "Ticket.h"

using namespace std;

class TicketManager {
  private:
    string m_name;
    int totalNumber;
    int count = 0;
    Ticket **ticket = nullptr;

  public:
    TicketManager() = delete;
    TicketManager(const string &name, const int &number);
    ~TicketManager();
    void buy(Ticket *t);
    void show() const;
    void showGeneralTicket(const bool &card);
    void showAdvancedTicket();

    friend ostream &operator<<(ostream &out, const TicketManager &manager);
};
ostream &operator<<(ostream &out, const TicketManager &manager);