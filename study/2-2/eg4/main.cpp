// 2.42p
#include <iostream>
#include <ctime>

using namespace std;

void test1() {
  int arr[5] = {}; // 0으로 초기화. 그냥 int arr[5]; 할시 junk값 들어옴.
  int arr2[5]{1, 2, 3, 4, 5};

  for (auto i: arr) {
    cout << i << '\t';
  }
  cout << endl;
}

void test2() {
  int arr[] = {1, 2, 3, 4, 5};
  cout << sizeof(arr) / sizeof(arr[0]) << endl;
  cout << size(arr) << endl;
}

void ex1() {
  constexpr int SIZE = 100;
  int arr[SIZE] = {};
  srand((unsigned)time(NULL));

  for (auto &i: arr) {
    i = rand() % 100;
  }

  for (auto i: arr) {
    cout << i << '\t';
  }
}

void test3() {
  constexpr int SIZE = 3;
  int arr[][SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (int i = 0; i < SIZE; i++) {
    for (auto j: arr[i]) {
      cout << j << '\t';
    }
    cout << endl;
  }
}

void ex2() {
  constexpr int ROW = 6, COL = 4;
  int arr[ROW][COL]{};
  char seat[2]{};
  char isEnd = 'n';

  for (int i = 0; i < COL; i++) {
    cout << '\t' <<i + 1 ;
  }
  cout << endl;
  for (int i = 0; i < ROW; i++)
  {
    cout << (char)('A' + i) << '\t';
    for (auto j : arr[i])
    {
      cout << (j == 0 ? "X" : "O") << '\t';
    }
    cout << endl;
  }

  do {
    cout << "좌석선택: ";
    cin >> seat;
    while ((int)(seat[0] - 'A') >= ROW || (int)(seat[1] - '1') >= COL) {
      cout << "좌석범위 다시: ";
      cin >> seat;
    }

    if (arr[(int)(seat[0] - 'A')][(int)(seat[1] - '1')] == 0) {
      arr[(int)(seat[0] - 'A')][(int)(seat[1] - '1')] = 1;

      for (int i = 0; i < COL; i++) {
        cout << '\t' << i + 1;
      }
      cout << endl;
      for (int i = 0; i < ROW; i++) {
        cout << (char)('A' + i) << '\t';
        for (auto j : arr[i]) {
          cout << (j == 0 ? "X" : "O") << '\t';
        }
        cout << endl;
      }
    } else {
      cout << "err" << endl;
    }

    cout << "종료?(y or n): ";
    cin >> isEnd;
  } while (isEnd == 'n');
}

int main(void) {
  // test1();
  // test2();
  // ex1();
  // test3();
  ex2();

  return 0;
}