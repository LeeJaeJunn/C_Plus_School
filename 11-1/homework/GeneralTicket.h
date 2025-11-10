#pragma once
#include "Ticket.h"

class GeneralTicket: public Ticket {
  private:
    bool payByCredit;
  public:
    GeneralTicket();
    GeneralTicket(const double &price, const bool &payByCredit = false);
    ~GeneralTicket();
    double getPrice() const;
    bool getPayByCredit() const;
    void show() const;
};