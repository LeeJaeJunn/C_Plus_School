#include <iostream>
#include "DocWriter.h"
#include "HTMLWriter.h"

using namespace std;

int main(void) {
  // DocWriter doc("test.txt", "greenjoa");
  // doc << "빵" << 2 << "우유" << 3;
  // doc.write();



  HTMLWriter html("index.html", "greenjoa");

  html.setFont("궁서체", 20, "blue");
  html << "빵" << 2 << "우유" << 3; // << 연산자 부모 클래스에서 상속됨.
  html.write();
  // a만약 자식 클래스에서 맞지 않을 경우 부모 클래스에서도 정의.

  // DocWriter doc = html; // 대입 연산. 다시 다운캐스팅 할 수 없음. 원래 자식객체의 정보는 사라짐
  // DocWriter *pDoc = &html; // 객체를 포인팅. 다운캐스팅 가능. 
  // DocWriter& rDoc = html; // 객체를 참조. 다운캐스팅 가능.

  // rDoc.write();

  return 0;
}