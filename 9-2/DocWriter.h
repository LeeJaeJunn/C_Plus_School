#pragma once
#include <string>

using std::string;

class DocWriter {
  protected:
    string fileName;
    string content;

  public:
    DocWriter();
    DocWriter(const string& fileName, const string& content);
    ~DocWriter();
    
    void setFileName(const string& fileName);
    void setContent(const string& content);
    void write();

    DocWriter& operator<<(const string &str);
    DocWriter& operator<<(const int &num);
};