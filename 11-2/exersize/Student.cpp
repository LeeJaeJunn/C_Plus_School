#include "Student.h"

Student::Student():Student("noname", 0) {}
Student::~Student() {}
Student::Student(const string &name, const int &score) : name(name), score(score) {}

string Student::getName() const {
  return name;
}
int Student::getScore() const {
  return score;
}

bool Student::operator==(const string &s) const {
  return this->name == s;
}

bool Student::operator==(const Student &s) const {
  return this->name == s.getName();
}

ostream &operator<<(ostream &out, Student &s) {
  out << s.name << " " << s.score;
  return out;
}