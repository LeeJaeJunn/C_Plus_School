#include <iostream>
#include <string>

using namespace std;
using std::move;

void printMessage(string &str) {
  cout << __FUNCTION__ << "(&)" << str << endl;
}
void printMessage(string &&str) {
  cout << __FUNCTION__ << "(&&)" << str << endl;
}

int main(void) {

  string str1 = "Hello";
  string str2 = "World";

  printMessage(str1);
  printMessage(str1 + str2);
  printMessage(std::move(str1));

  return 0;
}