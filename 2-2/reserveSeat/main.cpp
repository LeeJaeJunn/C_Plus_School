#include <iostream>

using namespace std;

void reservation() {
  constexpr int ROW = 6;
  constexpr int COL = 4;
  bool seats[ROW][COL]{};

  char isEnd = 't';
  char seat[2];

  do {
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

    cout << "좌석을 선택하세요 (예. A1) : ";
    cin >> seat;

    while ((int)(seat[0] - 'A') >= ROW || (int)(seat[1] - '1') >= COL) {
      cout << "잘못된 좌석입니다. 다시 선택해주세요 (예. A1) : ";
      cin >> seat;
    }

    if (seats[(int)(seat[0] - 'A')][(int)(seat[1] - '1')] == false) {
      seats[(int)(seat[0] - 'A')][(int)(seat[1] - '1')] = true;

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
    } else {
      cout << "예약 불가" << endl;
    }

    cout << "종료하시겠습니까? (y, n) : ";
    cin >> isEnd;
  } while (isEnd == 'n');

  
}

int main(void) {
  cout << "202112711 이제준" << endl;

  reservation();

  return 0;
}