#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student {
  private:
    string name;
    int score;

  public:
    Student();
    ~Student();
    Student(const string& name, const int& score);

    string getName() const;
    int getScore() const;

    bool operator==(const string &s) const;
    bool operator==(const Student &s) const;
    friend ostream &operator<<(ostream &out, Student &s);
};

ostream &operator<<(ostream &out, Student &s);
