#include <iostream>
#include <list>

using namespace std;

template<typename T>
void printArr(list<T> &l) {
  for (auto it = l.begin(); it != l.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

list<string> getStudent(list<list<string>> std, list<string> droplist);

int main(void) {
  list<list<string>> std;
  std.push_back({"greenjoa1", "bluejoa1", "greenjoa3"});
  std.push_back({"greenjoa1", "greenjoa3"});
  std.push_back({"redjoa1", "greenjoa2", "bluejoa2"});
  list<string> droplist({"greenjoa2", "bluejoa1"});

  auto student = getStudent(std, droplist);
  printArr(student);
  
  return 0;
}

list<string> getStudent(list<list<string>> std, list<string> droplist) {
  list<string> student;
  for(auto &i: std) {
    student.insert(student.end(), i.begin(), i.end());
  }
  student.sort();
  student.unique();
  for (auto &i: droplist) {
    student.remove(i);
  }

  return student;
}
