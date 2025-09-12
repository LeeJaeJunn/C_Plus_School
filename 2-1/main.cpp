#include <iostream>
#include <sstream>
#include <string>

#include "PointClass.h"
#include <fstream>

using namespace std;

void example1() {
  string myStr, name;
  int sum = 0;
  int temp;
  
  cout << "이름과 성적을 입력하세요 : ";
  getline(cin, myStr);
  stringstream ss(myStr);
  ss >> name;
  while(ss >> temp) {
    sum += temp;
  }
  cout << name << ':' << sum << endl;
}

// 지금은 처음 하나만 바뀜.
// 다 바꾸기.
void example2() {
  ifstream fin("testdata.txt");
  if(!fin.is_open()) {
    cout << "파일 읽기 실패" << endl;
    return;
  }
  string data;
  while (!fin.eof()) {
    string str;
    getline(fin, str);
    // data += str+' \n';
    data.append(str + '\n');
  }
  cout << data << endl;
  cout << "***********" << endl;

  string findStr, replaceStr;

  cout << "찾을 문자열 : ";
  getline(cin, findStr);
  cout << "바꿀 문자열 : ";
  getline(cin, replaceStr);

  int pos = data.find(findStr);
  if (pos != string::npos) {
    data.replace(pos, findStr.length(), replaceStr);
  } else {
    cout << "파일에 찾는 문자열이 없음" << endl;
    return;
  }
  cout << "*************" << endl;
  cout << data << endl;
}

int main(void) {
  std::cout << "202112711 이제준" << std::endl;

  // float price = 100.5f;
  // int quantity = 200;

  // stringstream ss;
  // ss << "price : " << price;
  // ss << ", Quantity : " << quantity;

  // cout << ss.str() << endl;

  // example1();
  example2();

  return 0;
}