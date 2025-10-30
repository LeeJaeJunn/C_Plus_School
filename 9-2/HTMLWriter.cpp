#include "HTMLWriter.h"
#include <iostream>
#include <fstream>

using namespace std;

HTMLWriter::HTMLWriter(): DocWriter("noname.html", "No Content") {}
// HTMLWriter::HTMLWriter(const string& fileName, const string& content): DocWriter(fileName, content) {}
HTMLWriter::HTMLWriter(
  const string& fileName, 
  const string& content, 
  const string& fontName,
  const int& fontSize, 
  const string& fontColor
): DocWriter(fileName, content) {
  cout << "HTML 생성자" << endl;
  this->fontName = fontName;
  this->fontColor = fontColor;
  this->fontSize = fontSize;
}
HTMLWriter::~HTMLWriter() {
  cout << "HTML 소멸자" << endl;
}

// 텍스트를 파일로 저장시킨다.
void HTMLWriter::write() {
  ofstream fout(fileName);
  fout << "<html><head><title>JaeJun's homePage</title></head>";
  fout << "<body><h1>202112711 이제준</h1><font face='";
  fout << fontName << "' size='" << fontSize << "' color='" << fontColor << "'>";
  fout << content;
  fout << "</font></body></html> ";
}
// 폰트를 지정한다.
void HTMLWriter::setFont(const string& fontName, const int& fontSize, const string& fontColor) {
  this->fontName = fontName;
  this->fontColor = fontColor;
  this->fontSize = fontSize;
}

HTMLWriter& HTMLWriter::operator<<(const string &str) {
  content += str + "<br>";
  return *this;
}
HTMLWriter& HTMLWriter::operator<<(const int &num) {
  content += num + "<br>";
  return *this;
}