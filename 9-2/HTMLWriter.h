#pragma once
#include "DocWriter.h"

class HTMLWriter: public DocWriter {
  protected:
    string fontName = "굴림체";
    int fontSize = 14;
    string fontColor = "red";

  public:
    HTMLWriter();
    // 아래랑 동일. 인자 2개인 객체 생성 가능. using구문 사용하면 부모 class 생성자 skip 가능
    using DocWriter::DocWriter;
    // HTMLWriter(const string& fileName, const string& content);
    HTMLWriter(
      const string& fileName, 
      const string& content, 
      const string& fontName,
      const int& fontSize, 
      const string& fontColor
    );
    ~HTMLWriter();

    // 텍스트를 파일로 저장시킨다.
    void write();
    // 폰트를 지정한다.
    void setFont(const string& fontName, const int& fontSize, const string& fontColor);

    HTMLWriter& operator<<(const string &str);
    HTMLWriter& operator<<(const int &num);
};