#include <iostream>

using namespace std;

void reservation() {
  constexpr int ROW = 6;
  constexpr int COL = 4;
  bool seats[ROW][COL]{};

  // 좌석 입력, 갱신, 종료조건 만들기.
  // 02.55p
  // 화면 지우는거 system.cle
  // 화면 정지 system. 뭐? 녹음확인.

  while (true) {
    for (int i = 0; i < COL; i++) {
      cout << '\t' << i + 1;
    }
    cout << endl;
    for (int i = 0; i < ROW; i++) {
      cout << static_cast<char>('A' + i) << '\t';

      for (int j = 0; j < COL; j ++) {
        cout << (seats[i][j] ? "O" : "X") << '\t';
      }

      cout << endl;
    }
  }
}

int main(void) {
  cout << "202112711 이제준" << endl;

  reservation();

  return 0;
}