#include "Player.h"
#include <string>
#include <iostream> 
// headerfile에 해도 되는데 headerfile에는 가능한 최소한 것만 include

using std::cout;
using std::endl;

void Player::setName(const string &name) {
  // this->m_name = name;
  m_name = name;
}

string Player::getName() {
  return m_name;
}

void Player::roll(Dice &dice1, Dice &dice2) {
  cout << m_name << "님께서 주사위를 던졌습니다." << endl;

  dice1.roll();
  dice2.roll();
  
  m_total = dice1.getFaceValue() + dice2.getFaceValue();
}

int Player::getTotal() {
  return m_total;
}
