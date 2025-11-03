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
    ~Ticket();

    int getNumber() const;
    double getPrice() const;
    void setPrice(const double &price);
    void show() const;
};