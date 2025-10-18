#include "Player.h"

Player::Player():Player("noName") {};
Player::Player(const string &name) {
  this->name = name;
}

void Player::setName(const string &name) {
  this->setName(name);
}
string Player::getName() {
  return this->name;
}
void Player::roll(Dice &dice1, Dice &dice2) {
  this->total = 0;
  dice1.roll();
  dice2.roll();
  total = dice1.getFaceValue() + dice2.getFaceValue();
}
int Player::getTotal() {
  return this->total;
}