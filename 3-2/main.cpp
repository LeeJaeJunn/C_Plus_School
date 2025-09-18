#include <iostream>
#include <string>
#include <fstream>

// 윈도우 전용
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif // !DBG_NEW
#endif

using namespace std;

int **loadSeats(const string &fileName, int &row, int &col, int &reserved); 
void printSeats(int **&seats, const int row, const int col);
void printMenu(int **&seats, const int row, const int col, int reserved);
void reservedSeat(int **&seats, const int row, const int col, int &reserved);
// 종료메뉴 선택 => 파일에 저장 후 메모리 삭제.

int main(void) {
  // 윈도우에서만.
  // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  cout << "202112711 이제준" << endl;
  string fileName = "seats.txt";
  int row = 0, col = 0, reserved = 0;
  int **seats = loadSeats(fileName, row, col, reserved);

  if (seats == nullptr) {
    cout << "파일 읽기 실패" << endl;
    return 0;
  }

  // printSeats(seats, row, col);
  printMenu(seats, row, col, reserved);

  // 출력은 ofstream

  return 0;
}

int **loadSeats(const string &fileName, int &row, int &col, int &reserved) {
  ifstream file(fileName);
  if (!file.is_open()) {
    return nullptr;
  }
  file >> row >> col;
  
  int **seats = new int *[row];
  for (int i = 0; i < row; i ++) {
    seats[i] = new int[col];
    for (int j = 0; j < col; j++) {
      file >> seats[i][j];
      if (seats[i][j] != 0) {
        reserved++;
      }
    }
  }
  return seats;
}

void printSeats(int **&seats, const int row, const int col) {
  for (int i = 0; i < col; i++) {
    cout << '\t' << i + 1;
  }
  cout << endl;
  for (int i = 0; i < row; i++) {
    cout << static_cast<char>('A' + i) << '\t';

    for (int j = 0; j < col; j++) {
      cout << (seats[i][j] != 0 ? "O" : "X") << '\t';
    }
    cout << endl;
  }
}

void printMenu(int **&seats, const int row, const int col, int reserved) {
  int selected = 0;
  
  do {
    system("clear");
    cout << "1)좌석현황\t2)좌석예약\t3)좌석취소\t4)종료" << endl;
    cout << "메뉴선택: ";
    cin >> selected;
    if (cin.fail()) {
      cin.clear();
      cin.ignore(1024, '\n');
      continue;
    }

    switch (selected) {
    case 1:
      printSeats(seats, row, col);
      break;
    case 2:
      reservedSeat(seats, row, col, reserved);
      break;
    case 3:
      break;
    case 4: 
      break;
    }
    // system("pause");
    system("read -n 1 -s -p \"Press any key to continue...\"");
  } while (selected != 4);
}

void reservedSeat(int **&seats, const int row, const int col, int &reserved) {
  if (row * col == reserved) {
    cout << "좌석 예약 마감" << endl;
    return;
  }
  char x;
  int y;
  while(true) {
    system("clear");
    printSeats(seats, row, col);
    cout << "좌석을 선택하세요 ex)A1 (종료:00)" << endl;
    cout << "좌석번호 입력: ";
    cin >> x >> y;
    if (x == '0' && y == 0) {
      cout << "메뉴로 이동합니다" << endl;
      break;
    }
    int r = x - 'A';
    int c = y - 1;

    if (r >= row || r < 0 || c >= col || c < 0) {
      cout << "잘못된 좌석 선택입니다. 다시 선택해주세요." << endl;
      system("read -n 1 -s -p \"Press any key to continue...\"");
    } else if (seats[r][c] != 0) {
      cout << "이미 예약된 좌석입니다. 다시 선택하세요." << endl;
      system("read -n 1 -s -p \"Press any key to continue...\"");
    } else {
      // 예약번호 생성. 아래 num을 중복되지 않게 고치기.
      int num = (r + 1) * 100 + (c + 1);
      seats[r][c] = num;
      reserved++;
      cout << "예약 완료, 예약번호: " << num << " 입니다." << endl;
      break;
    }

  }
} // 좌석선택하고 예약, 범위체크, 예약작업
