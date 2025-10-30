#include "DocWriter.h"
#include <iostream>
#include <fstream>

using namespace std;

DocWriter::DocWriter(): DocWriter("noname.txt", "no content") {}
DocWriter::DocWriter(const string& fileName, const string& content) 
:fileName(fileName), content(content) {
  cout << "DocWriter 생성자" << endl;
  // this->fileName = fileName;
  // this->content = content;
}
DocWriter::~DocWriter() {
  cout << "DocWriter 소멸자" << endl;
}

void DocWriter::setFileName(const string& fileName) {
  this->fileName = fileName;
}
void DocWriter::setContent(const string& content) {
  this->content = content;
}
void DocWriter::write() {
  ofstream fout(fileName);
  fout << content << endl;
}

DocWriter& DocWriter::operator<<(const string &str) {
  content += str + "\n";
  return *this;
}
DocWriter& DocWriter::operator<<(const int &num) {
  content += to_string(num) + "\n";
  return *this;
}