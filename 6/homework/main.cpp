#include <iostream>
#include <memory>
#include <cmath>
#include <ctime>
#include <iomanip>

// 윈도우.
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif // !DBG_NEW
#endif

using namespace std;
using sharedDptr = shared_ptr<shared_ptr<int[]>[]>;

sharedDptr createBoard(int &row, int &col);
void printOriginBoard(sharedDptr &board, const int &row, const int &col);
void printBoard(sharedDptr &board, const int &row, const int &col);
void inputBoard(sharedDptr &board, const int &row, const int &col, int &count);
void deleteBoard(int **&board, const int &row, const int &col);

int main(void) {
  // 윈도우.
  // _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  cout << "202112711 이제준" << endl;

  srand((unsigned)time(NULL));
  int row = 0, col = 0;
  int count = 0;
  sharedDptr board = createBoard(row, col);

  // printOriginBoard(board, row, col);
  // cout << "========" << endl;
  inputBoard(board, row, col, count);

  return 0;
}

sharedDptr createBoard(int &row, int &col) {
  int size;

  while(true) {
    cout << "게임에 사용할 카드의 개수를 입력해주세요. 반드시 짝수여야 합니다.(예: 4): ";
    cin >> size;

    if (cin.fail()) {
      cout << "잘못 입력되었습니다. 짝수를 입력해주세요." << endl;
      cin.clear();
      cin.ignore(1024, '\n');
      continue;
    } else if (size <= 0) {
      cout << "짝수를 입력해 주세요." << endl;
      continue;
    } else if (size % 2 == 1) {
      cout << "짝수를 입력해 주세요." << endl;
      continue;
    }

    // 10 입력 => 1,2,3,4,5 가 각각 2번씩 들어가야함.
    row = static_cast<int>(sqrt(size));
    while (size % row != 0) {
      row++;
    }
    col = size / row;
    break;
  }

  sharedDptr board = make_shared<shared_ptr<int[]>[]>(row);
  for (size_t i = 0; i < row; i++) {
    board[i] = make_shared<int[]>(col);
    for (size_t j = 0; j < col; j++) {
      board[i][j] = 0;
    }
  }

  for (size_t i = 1; i <= size / 2; i++) {
    for (size_t j = 0; j < 2; j++) {
      while (true) {
        int r = rand() % row;
        int c = rand() % col;

        if (board[r][c] == 0) {
          board[r][c] = i;
          break;
        }
      }
    }
  }

  return board;
}

void printOriginBoard(sharedDptr &board, const int &row, const int &col) {
  cout << "    ";
  for (size_t i = 0; i < col; i++) {
    cout << left << setw(3) << i;
  }
  cout << endl << "   ";
  for (size_t i = 0; i < col; i++) {
    cout <<  left << setw(3) << "---";
  }
  cout << endl;
  for (size_t i = 0; i < row; i++) {
    cout << i <<" | ";
    for (size_t j = 0; j < col; j++) {
      cout << left << setw(3) << board[i][j];
    }
    cout << endl;
  }
}

void printBoard(sharedDptr &board, const int &row, const int &col) {
  cout << "    ";
  for (size_t i = 0; i < col; i++) {
    cout << left << setw(3) << i;
  }
  cout << endl << "   ";
  for (size_t i = 0; i < col; i++) {
    cout <<  left << setw(3) << "---";
  }
  cout << endl;
  for (size_t i = 0; i < row; i++) {
    cout << i <<" | ";
    for (size_t j = 0; j < col; j++) {
      if (board[i][j] < 0) {
        cout << left << setw(3) << -board[i][j];
      } else {
        cout << left << setw(3) << "X";
      }
    }
    cout << endl;
  }
}

void inputBoard(sharedDptr &board, const int &row, const int &col, int &count) {
  int r1, r2, c1, c2;
  // printBoard(board, row, col);
  while (true) {
    printBoard(board, row, col);
    while (true) {
      cout << "행과 열 입력(예: 3 4): ";
      cin >> r1 >> c1;
      if (cin.fail()) {
        cout << "잘못 입력되었습니다." << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        continue;
      } else if (r1 >= row || r1 < 0 || c1 >= col || c1 < 0) {
        cout << "범위가 잘못되었습니다." << endl;
        continue;
      } else if (board[r1][c1] < 0) {
        cout << "이미 맞춘 카드입니다." << endl;
        continue;
      }
      board[r1][c1] = -board[r1][c1];
      printBoard(board, row, col);
      break;
    }

    while (true) {
      cout << "두 번째 행과 열 입력(예: 3 4): ";
      cin >> r2 >> c2;
      if (cin.fail()) {
        cout << "잘못 입력되었습니다." << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        continue;
      } else if (r2 >= row || r2 < 0 || c2 >= col || c2 < 0) {
        cout << "범위가 잘못되었습니다." << endl;
        continue;
      } else if (board[r2][c2] < 0) {
        cout << "이미 뒤집은 카드입니다." << endl;
        continue;
      }
      board[r2][c2] = -board[r2][c2];
      printBoard(board, row, col);
      break;
    }

    if (board[r1][c1] == board[r2][c2]) {
      cout << "맞췄습니다! " << endl;
      count += 2;
      // printBoard(board, row, col);
    } else {
      cout << "불일치..." << endl;
      board[r1][c1] = -board[r1][c1];
      board[r2][c2] = -board[r2][c2];
      // printBoard(board, row, col);
    }

    if (count == row * col) {
      cout << "모든 카드를 맞췄습니다. 게임 종료" << endl;
      return;
    }
    // system("pause"); // window
    system("read -n 1 -s -p \"Press any key to continue...\""); // 맥
    // system("cls"); // 윈도우
    system("clear"); // 맥
  }
}

void deleteBoard(int **&board, const int &row, const int &col) {
  for (size_t i = 0; i < row; i ++) {
    delete[] board[i];
  }
  delete[] board;
  board = nullptr;
}