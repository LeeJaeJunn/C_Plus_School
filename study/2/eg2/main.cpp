#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void test1() {
  string s1 = "Hello";
  string s2 = "World";
  string s3 = s1 + ' ' + s2;
  cout << s3 << endl;
}

void test2() {
  string s1 = "Good";
  string s2 = "Bad";
  string s3("SoSo");

  int result = s1.compare(s2);
  cout << result << endl;

  if (s1 == "Good") {
    cout << s1 << endl;
  } else if (s2 == "Bad") {
    cout << s2 << endl;
  } else {
    cout << "SoSo" << endl;
  }
}

void test3() {
  string s1 = "Hello";
  string s2 = "World";

  string s3 = s1;
  const char *s4 = s1.data();
  s3 = "aaa";
  cout << s1 << " " << s3 << endl;

  s4 = "asd";
  cout << s1 << " " << s4 << endl;
}

void test4() {
  string s1 = "123";
  int i1 = stoi(s1);

  int i2 = 321;
  string s2 = to_string(i2);
  
  cout << s2 << "타입 : " << typeid(s2).name() << endl;
  cout << i1 << "타입 : " << typeid(i1).name() << endl;

  cout << s1 << ' ' << s1.length() << endl;\
}

void test5() {
  string context, line;

  do {
    getline(cin, line);
    context += line + '\n';
  } while (!line.empty());
  cout << line.empty() << endl;

  cout << context << endl;
}

void test6() {
  string str("Test string");
  for (int i = 0; i < str.length(); i++)
  {
    cout << str[i] << " = " << str.at(i) << endl;
  }

  cout << "-------" << endl;
  cout << str.front() << " " << str.back() << endl;
  str.front() = 'K';
  str.back() = 'H';
  cout << str << endl;
}


void test7() {
  string str1("Hello");
  string str2{"World!"};
  cout << str1 << " " << str2 << endl;
  cout << str1.append(str2, 0, 5) << endl;
  cout << str1.insert(5, " ") << endl;
  cout << str1.erase(5, 10) << endl;
  cout << str1.replace(1, 4, "ELLO") << endl;

  str1.swap(str2);
  cout << str1 << " " << str2 << endl;
}

void test8() {
  string str, findStr;
  ifstream file("test.txt");
  size_t pos;

  if (!file.is_open()) {
    cout << "파일 읽기 실패" << endl;
    return;
  }

  while (!file.eof()) {
    string str2;
    getline(file, str2);

    cout << "this is a str2 : " << str2 << endl;
    // str += str2 + '\n';
    str.append(str2 + '\n');
  }
  cout << str << endl;

  getline(cin, findStr);
  cout << "찾을 문자열 : " << findStr << endl;

  pos = str.find(findStr);
  cout << "찾을 문자열 위치(pos) : " << pos << endl;

  cout << str.substr(pos, findStr.length()) << endl;
}

void example1() {
  const size_t SIZE = 5;
  string names[SIZE];
  cout << "이름 5명 입력 : ";
  for (auto &i : names) {
    cin >> i;
  }

  // sort(names, names + 5);

  // 버블 정렬
  for (int i = 0; i < SIZE - 1; i++) {
    for (int j = 0; j < SIZE - 1 - i; j++) {
      if (names[j] > names[j + 1]) {
        swap(names[j], names[j + 1]);
        
      }
    }
  }
  for (auto i : names) {
    cout << i << endl;
  }
}

void changeString() {
  string str, findStr, changeStr;
  ifstream file("test.txt");

  cout << "찾을 문자열을 입력해주세요 : ";
  getline(cin, findStr);
  cout << "바꿀 문자열을 입력해주세요 : ";
  getline(cin, changeStr);

  if (!file.is_open()) {
    cout << "파일 읽기 실패" << endl;
    return;
  }

  while (!file.eof()) {
    string str2;
    getline(file, str2);
    str.append(str2 + '\n');
  }
  cout << str << endl;
}

int main(void) {
  // test1();
  // test2();
  // test3();
  // test4();
  // test5();
  // test6();
  // test7();
  // test8();
  // example1();
  changeString();

  return 0;
}