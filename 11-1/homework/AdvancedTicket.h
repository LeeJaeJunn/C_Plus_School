#pragma once
#include "Ticket.h"

class AdvancedTicket: public Ticket {
  private:
    int advancedDays;
  public:
    AdvancedTicket();
    AdvancedTicket(const double &price, const int &advancedDays = 0);
    ~AdvancedTicket();

    double getPrice() const;
    int getAdvancedDays() const;
    void show() const;
};