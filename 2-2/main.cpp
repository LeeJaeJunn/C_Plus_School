#include <iostream>
#include <ctime>

using namespace std;

void example() {
  constexpr int SIZE = 10;
  int num[SIZE];

  int index = 0;

  srand((unsigned)time(NULL));
  cout << "==============" << endl;
  cout << "인덱스\t값" << endl;
  cout << "==============" << endl;

  // for (int i = 0; i < SIZE; i++) {
  //   num[i] = rand() % 100;
  //   cout << i << '\t' << num[i] << endl;
  // }

  for (auto &i : num) {
    i = rand() % 100;
    cout << index << '\t' << i << endl;
    index++;
  }

  
}

int main(void) {
  cout << "202112711 이제준" << endl;

  example();

  return 0;
}