#include <iostream>
#include <list>

#include "CMyPoint.h"

using namespace std;

template<typename T>
void printArr(vector<T>& v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

// void eg1() {
//   list<string> name1{ "aa","bb","ca","bb","bb","cb" };
//   list<string> name2{ "aa","bb","ca" };

//   name1.sort();

//   for (auto it = name1.begin(); it != name1.end(); it++) {
//     cout << *it << endl;
//   }
// }

// void eg2() {
//   list<int> list1({1, 2, 3, 3, 3, 4, 3, 5});
//   list1.unique();

//   printArr(list1);
// }

// void eg3() {
//   list<CMyPoint> list2;
//   list2.push_back(CMyPoint(10, 10));
//   list2.emplace_back(20, 20);
//   list2.emplace_back(20, 20);
//   list2.emplace_back(20, 20);
//   list2.push_front(CMyPoint(30, 30)); 
//   list2.unique();
//   printArr(list2);

//   list<CMyPoint> list3;
//   list3.push_back(CMyPoint(40, 50));
//   list3.push_back(CMyPoint(50, 50));
//   list2.splice(list2.end(), list3); // list3는 비워짐
//   cout << list3.size() << endl;
//   printArr(list2);
// }

void eg4() {
  list<string> std1({"g1", "g2", "g3"});
  list<string> std2({"b1", "b2"});
  list<string> std3({"r1"});

  vector<list<string>> std; // 2차원 배열. vector안에 vecor 넣을 수 있음
  std.push_back(std1);
  std.push_back(std2);
  std.push_back(std3);

  vector<string> stdname;
  for (auto s: std) {
    for (auto t : s) {
      stdname.push_back(t);
    }
  }
  printArr(stdname);
}

int main(void) {
  eg4();

  return 0;
}