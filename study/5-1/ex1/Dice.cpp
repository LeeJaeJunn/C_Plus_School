#include "Dice.h"
#include <cstdlib>


Dice::Dice():faceValue(0) {}
void Dice::roll() {
  faceValue = rand() % 6 + 1;
}
int Dice::getFaceValue() {
  return faceValue;
}