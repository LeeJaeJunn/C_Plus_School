#pragma once

class Ticket {
  protected:
    int number;
    double price;
    static inline int count = 1;

  public:
    Ticket();
    Ticket(const double &price);
    // Ticket(const int &number, const double &price);
    virtual ~Ticket();

    int getNumber() const;
    virtual double getPrice() const;
    void setPrice(const double &price);
    virtual void show() const;
};