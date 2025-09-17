#include <iostream>
#include <string>
#include <utility>

using namespace std;

// const_cast
void test1() {
  const string &str1 = "ABC"; // string &str1 = "ABC" 이건 안됨. (reference 연산자.)
  
  string &str2 = const_cast<string&>(str1); // const 제거.
  str2 = "def";
  cout << str1 << endl; // def

  // const string &str3 = str2; 아래랑 같음. 이렇게 하는게 올바름. 굳이 한번 더 const_cast할필요 없음.
  const string &str3 = const_cast<const string&>(str2);
  // const string &str4 = as_const(str2); // 지금 c++ 14로 되어있어서 이게 안됨.
}

// static_cast
void test2() {
  char a = 55;
  int *p = (int*)&a;
   // c스타일. 에러 안남. 위험. char 타입 주소를 가진 &a를 강제로 int 타입으로 바꿈.
   // (1바이트 크기이지만 int로 바꾸며 4바이트를 읽음.3바이트는 garbage data)
  cout << a << '\t' << *p << endl; // 이상한 값 출력

  char a2 = 55;
  // int *p = static_cast<int *>(&a); // 에러 일으킴. 관련없는 데이터타입.

  int i = 3;
  int j = 4;
  double result = static_cast<double>(i) / j; // i를 double로 형변환.

  cout << i << " / " << j << " = " << result << endl;

  double k = 1;
}

// reinterpret_cast 주로 void* 타입 명시 시에 사용.
void test3() {
  int x = 10;
  void *xp = &x;
  int *xpp = reinterpret_cast<int *>(xp);
  unsigned char *p = reinterpret_cast<unsigned char *>(xp);
  cout << "x : " << x << " *xpp : " << *xpp << endl;
  cout << hex;
  for (int i = 0; i < sizeof(x); i++) {
    cout << static_cast<int>(p[i]) << '\n';
  }
}

void test4() {
  using IntPtr = int *;
  int a = 10;
  cout << "a : " << a << endl;
  IntPtr b = &a;
  *b = 20;

  cout << "a : " << a << " b : " << b << " *b : " << *b << endl;
}

// C++에서는 nested function 불가능 (함수 안 함수정의 불가)
const string message = "Hello World";
const string& getString() {
    return message;
}
// auto는 constant, reference가 제거됨. 따로 붙여줘야함.
void test5() {
  cout << getString() << endl;
  cout << "==========" << endl;

  auto s1 = getString();
  cout << s1 << endl;
  s1 = "Hi World";
  cout << "message: " << message << " s1: " << s1 << endl; // 원본 message는 const라 값이 바뀌지 않음.

  const auto &s3 = getString();
}

void test6() {
  // decltype(getString()) s3;
  // const string이랑 같음.

  decltype(auto) s3 = getString();
}

int main(void) {
  // test1();
  // test2();
  // test3();
  // test4();
  // test5();
  test6();

  return 0;
}