#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printArr(vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); it++) { // 이더레이터
    cout << *it << " ";
  }
  cout << endl;
}

void eg1() {
  vector<int> intVec;

  for (int i = 0; i < 20; i++) {
    intVec.push_back(i);
    cout << intVec.size() << " , " << intVec.capacity() << endl;
  }
}

void eg2() {
  vector<int> arr1({1, 2, 3, 4, 5});
  printArr(arr1);

  vector<double> arr2;
  arr2.push_back(10.5);
  arr2.push_back(10.5);
  arr2.push_back(10.5);
  arr2.insert(arr2.begin(), 10.6);
  printArr(arr2);
}

int main(void) {
  // eg1();
  eg2();

  return 0;
}