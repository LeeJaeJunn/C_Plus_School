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
void cancelSeat(int **&seats, const int row, const int col, int &reserved ); // 좌석취소
void saveSeat(
    const string &fileName,
    int **&seats,
    const int row,
    const int col
);
void deleteSeat(int **&seats, const int row, const int col);
// 좌석 취소 구문 만들기. 과제

int main(void) {
  // 윈도우에서만.
  // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  cout << "202112711 이제준" << endl;
  string fileName = "seats.txt";
  int row = 0, col = 0, reserved = 0;
  int **seats = loadSeats(fileName, row, col, reserved);

  if (seats == nullptr)
  {
    cout << "파일 읽기 실패" << endl;
    return 0;
  }

  // printSeats(seats, row, col);
  printMenu(seats, row, col, reserved);
  saveSeat(fileName, seats, row, col);
  deleteSeat(seats, row, col);

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
    // system("cls"); // 윈도우
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
      cancelSeat(seats, row, col, reserved);
      break;
    case 4: 
      break;
    }
    // system("pause"); // window
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
      cin.clear();
      cin.ignore(1024, '\n');
      // system("pause"); // window
      system("read -n 1 -s -p \"Press any key to continue...\"");
    } else if (seats[r][c] != 0) {
      cout << "이미 예약된 좌석입니다. 다시 선택하세요." << endl;
      // system("pause"); // window
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
}

void cancelSeat(int **&seats, const int row, const int col, int &reserved ) {
  char x;
  int y;
  int reserveId;

  if (reserved == 0) {
    cout << "예약된 좌석이 없습니다." << endl;
    return;
  }

  while (true) {
    system("clear");
    printSeats(seats, row, col);
    cout << "취소할 좌석을 입력해주세요 ex)A1 (종료: 00)" << endl;
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
      cin.clear();
      cin.ignore(1024, '\n');
      // system("pause"); // window
      system("read -n 1 -s -p \"Press any key to continue...\"");
    } else if(seats[r][c] == 0) {
      cout << "예약되지 않은 좌석입니다. 다시 선택해주세요" << endl;
      // system("pause"); // window
      system("read -n 1 -s -p \"Press any key to continue...\"");
    } else {
      while (true) {
        cout << "예약번호를 입력해 주세요(선택좌석:" << x<<y << " 종료: 0)" << endl;
        cout << "예약번호 입력: ";
        cin >> reserveId;
        if (cin.fail()) {
          cout << "예약번호가 잘못 입력되었습니다. 다시 입력해주세요." << endl;
          cin.clear(); 
          cin.ignore(1024, '\n');
          continue;
        }

        if (reserveId == 0) {
          break;
        }

        if (seats[r][c] == reserveId) {
          seats[r][c] = 0;
          reserved--;
          cout << "취소 완료"  << endl;
          break;

        } else {
          cout << "예약번호가 잘못 입력되었습니다. 다시 입력해주세요." << endl;
        }
      }
      break;
    }
  }
}

void saveSeat(
  const string &fileName,
  int **&seats,
  const int row,
  const int col
) {
  ofstream file(fileName);
  if (!file.is_open()) {
    cout << "파일 오류" << endl;
    return;
  }
  file << row << " " << col << endl;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      file << seats[i][j] << " ";
    }
    file << endl;
  }
}

// 메모리 정리 (누수방지.)
void deleteSeat(int **&seats, const int row, const int col) {
  for (int i = 0; i < row; i++) {
    delete[] seats[i]; // 층 정보 삭제.
  }
  delete[] seats;
  seats = nullptr;
}