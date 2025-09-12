#include <iostream>
#include <fstream>

using namespace std;

void changeString() {
  string data;
  string findStr, replaceStr;

  ifstream fin("testData.txt");
  if(!fin.is_open()) {
    cout << "파일 읽기 실패" << endl;
    return;
  }
  
  while (!fin.eof()) {
    string str;
    getline(fin, str);
    // data += str+' \n';
    data.append(str + '\n');
  }
  cout << data << endl;
  cout << "***********" << endl;
  cout << "찾을 문자열 : ";
  getline(cin, findStr);
  cout << "바꿀 문자열 : ";
  getline(cin, replaceStr);

  int pos = data.find(findStr);

  while (pos != string::npos) {
    data.replace(pos, findStr.length(), replaceStr);
    pos = data.find(findStr, replaceStr.length());
  }

  cout << "*************" << endl;
  cout << data << endl;
}

int main(void) {
  cout << "202112711 이제준" << endl;
  changeString();
}