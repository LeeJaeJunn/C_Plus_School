#pragma once
#include "DocWriter.h"

class HTMLWriter : public DocWriter {
  protected:
    string fontName;
    int fontSize;
    string fontColor;
  public:
    HTMLWriter();
    ~HTMLWriter();
    // 텍스트를 파일로 저장시킨다.
    void Write();
    // 폰트를 지정한다.
    void SetFont(const string& fontName, int fontSize,
    const string& fontColor);
};