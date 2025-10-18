#pragma once
#include <string>
#include "Dice.h"

using std::string;

class Player {
  private:
    string name;
    int total;

  public:
    Player();
    Player(const string &name);
    void setName(const string &name);
    string getName();
    void roll(Dice &dice1, Dice &dice2);
    int getTotal();
};