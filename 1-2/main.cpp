#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

void example01() {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) (
      cout << setw(5) << j << "*" << j << "=" << i*j << "\t"
    );
    cout << endl;
  }
}

void example02() {
  int start, end;
  char isEnd;
  cout << "구구단의 출력을 원하는 범위를 입력하세요(시작, 끝) : ";
  cin >> start >> end;

  if (start > end) {
    cout << "두 번쨰 입력 숫자가 더 크므로, 시작과 끝의 값을 바꿔서 출력 할까요(y/n)? ";
    cin >> isEnd;
    if (isEnd == 'y') {
      // case 1
      // int temp;
      // temp = start;
      // start = end;
      // end = temp;

      // case 2
      // start ^= end;
      // end ^= start;
      // start ^= end;

      //case 3
      swap(start, end);
    } else {
      return;
    }
  }

  cout << endl;
  for (int i = 1; i < 9; i++) {
    for (int j = start; j < end + 1; j++) (
      cout <<  j << "*" << j << "=" << i*j << "\t"
    );
    cout << endl;
  }
}

void example3() {
  string name, addr;
  int tel;
  // cin >> name >> tel >> addr;
  cin >> name >> tel; // 공백x
  if (cin.fail()) {
    cin.clear(); // 비트를 입력받을 수 있는 상태로 초기화.
    cin.ignore(); // 버퍼를 비움
  }

  // cin.clear();
  // cin.ignore(1000, '\n'); // default 값으로 사용해도 됨.

  getline(cin, addr); // 공백 포함 엔터로 종료

  cout << name << "\t" << tel << "\t" << addr << endl;
}

int main(void) {
  cout << "202112711 이제준" << endl;
  // example01();
  // example02();
  example3();
  return 0;
}