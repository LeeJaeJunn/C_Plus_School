#include <iostream>
#include "Dice.h"
#include "Player.h"
#include "Dice.cpp"
#include "Player.cpp"
#include <ctime>

// 전처리 지시자가 없을 시 중첩 inclde하면 에러남.

using namespace std;

int main(void) {
  srand((unsigned)time(NULL));

  Dice dice1, dice2;
  Player player1, player2;
  player1.setName("홍길동");
  player2.setName("김길동"); // 메모리 2개 별도 생성

  player1.roll(dice1, dice2);
  player2.roll(dice1, dice2);

  if (player1.getTotal() == player2.getTotal()) {
    cout << "무승부" << endl;
  }
  else if (player1.getTotal() > player2.getTotal())
  {
    cout << player1.getName() << " 승" << endl;
  } else {
    cout << player2.getName() << " 승" << endl;
  }

  return 0;
}