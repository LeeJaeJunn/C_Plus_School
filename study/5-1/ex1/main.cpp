#include <iostream>
#include <cstdlib>
#include "Player.cpp"
#include "Dice.h"
#include "Player.h"
#include "Dice.cpp"

using namespace std;

int main(void) {
  srand((unsigned)time(NULL));
  Dice d1, d2;
  Player p1, p2;

  p1.roll(d1, d2);
  p2.roll(d1, d2);
  cout << p1.getTotal() << "\t" << p2.getTotal() << endl;

  return 0;
}