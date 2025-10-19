// 59
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void test1() {
  string myStr, data;
  stringstream ss;
  

  cout << "이름, kor eng math : ";
  getline(cin, myStr);
  ss.str(myStr);
  
  cout << data << endl;
  while (ss >> data)
  {
    cout << data << endl;
  }
}

void test2() {
  string myStr, name;
  stringstream ss;
  int sum = 0;
  int temp;

  cout << "이름 성적(3개)";
  getline(cin, myStr);
  ss.str(myStr);
  ss >> name;
  while (ss >> temp) {
    cout << temp << " ";
    sum += temp;
  }
  cout << endl;
  cout << name << sum << endl;
}

void ex() {
  string inputStr, name;
  int sum = 0;
  int temp;
  stringstream ss;

  cout << "Enter your data(name kor eng math) : ";
  getline(cin, inputStr);
  ss.str(inputStr);

  ss >> name;
  while (ss >> temp) {
    sum += temp;
  }

  cout << name << " : " << sum << endl;
}

int main(void) {
  // test1();
  test2();
  // ex();

  return 0;
}