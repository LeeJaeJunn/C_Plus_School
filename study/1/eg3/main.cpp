// 50p
#include <iostream>
#include <iomanip>

using namespace std;

void test1() {
  int w, h;
  cout << "너비 높이 입력 : ";
  cin >> w >> h;
  cout << endl;
  cout << w << '\t' << h << endl;
}

void test2() {
  string myStr;
  cout << "name? : ";
  getline(cin, myStr);
  cout << myStr << endl;
}

void test3() {
  char *myStr;
  cout << "name? : ";
  cin.getline(myStr, 100);
  cout << myStr << endl;
}

void ex() {
  int start, finish;
  cout << "시작, 끝 입력 (시작, 끝) : ";
  cin >> start >> finish;

  if (start > finish) {
    char isChange;
    cout << "시작이 더 큼. 시작 끝 바꿔?(y,n) : ";
    cin >> isChange;
    cout << endl;

    if (isChange == 'y') {
      int temp;
      temp = start;
      start = finish;
      finish = temp;
    } else {
      return;
    }
  }

  for (size_t i = 1; i < 10; i++) {
    for (size_t j = start; j <= finish; j++) {
      cout << j << setw(2) << '*' << setw(2) << i << setw(2) << '=' << setw(3) << i * j << '\t';
    }
    cout << endl;
  }
}

int main(void) {
  // test1();
  // test2();
  // test3();
  ex();

  return 0;
}