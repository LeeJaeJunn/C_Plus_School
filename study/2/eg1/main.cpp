// ~7

#include <iostream>
#include <climits>
#include <string>

using namespace std;

struct PointStruct {
  string s;
  int x;
  int y;
};

class PointClass {
  private:
    string s;
    int x;
    int y;
  public:
    PointClass(string s, int x, int y) {
      this->s = s;
      this->x = x;
      this->y = y;
    }
    void print() {
      cout << s << x << y << endl;
    }
    void changeS(string s) {
      this->s = s;
    }
};

void test1() {
  int i = INT_MAX;
  int c = CHAR_MAX;
  short s = SHRT_MAX;
  long int l = LONG_MAX;

  cout << i << endl;
  cout << c << endl;
  cout << s << endl;
  cout << l << endl;
}

void test2() {
  char c = 'a'; // 복사 초기화 (Copy initialization)
  char c2('b'); // 직접 초기화 (direct initialization)
  char c3{'c'}; // 유니폼 초기화 (uniform initialization)

  cout << c << endl;
  cout << c2 << endl;
  cout << c3 << endl;
}

void test3() {
  PointStruct pt1 = {"ljj", 1, 2};
  PointStruct pt2{"ljjjjj", 3, 4};

  cout << pt1.s << pt1.x << pt1.y << endl;
  cout << pt2.s << pt2.x << pt2.y << endl;
}

void test4() {
  PointClass pt1("Ljj", 10, 10);
  PointClass pt2{"jjj", 20, 30};

  pt1.print();
  pt2.print();

  pt1.changeS("jjjjjjllasdl");
  pt1.print();
}

int main(void) {
  // test1();
  // test2();
  // test3();
  test4();

  return 0;
}