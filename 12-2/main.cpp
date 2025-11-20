#include <iostream>
#include <list>

#include "../12-1/exersize2/CMyPoint.h"

using namespace std;

template<typename T>
void printArr(list<T>& v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void eg1() {
  list<string> name1{ "aa","bb","ca","bb","bb","cb" };
  list<string> name2{ "aa","bb","ca" };

  name1.sort();

  for (auto it = name1.begin(); it != name1.end(); it++) {
    cout << *it << endl;
  }
}

void eg2() {
  list<int> list1({1, 2, 3, 3, 3, 4, 3, 5});
  list1.unique();

  printArr(list1);
}

int main(void) {
  list<CMyPoint> list2;
  list2.push_back(CMyPoint(10, 10));
  list2.emplace_back(20, 20);
  list2.emplace_back(20, 20);
  list2.emplace_back(20, 20);
  list2.push_front(CMyPoint(30, 30));
  
  list2.unique();
  printArr(list2);

  return 0;
}