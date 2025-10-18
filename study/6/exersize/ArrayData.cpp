#include "ArrayData.h"
#include <iostream>

using namespace std;

ArrayData::ArrayData():ArrayData(5) {}
ArrayData::ArrayData(const int &capacity, const int &used)
:capacity(capacity), used(used), 
  // data(new double[capacity]) 
  data(make_shared<double[]>(capacity))
{
  cout << "생성자 호출" << endl;
}
ArrayData::ArrayData(ArrayData &arr):ArrayData(arr.capacity, arr.used) {
  cout << "복사생성자 호출" << endl;
  for (size_t i = 0; i < used; i++) {
    data[i] = arr.data[i];
  }
}
ArrayData::ArrayData(ArrayData &&arr) noexcept:capacity(arr.capacity), used(arr.used), data(arr.data) {
  cout << "이동생성자 호출" << endl;
  arr.data = nullptr;
}
ArrayData::~ArrayData() {
  // if (data != nullptr) {
  //   delete[] data;
  // }
  // data = nullptr;
}

void ArrayData::addElement(const double &num) {
  if (used >= capacity) {
    cout << "배열 가득참" << endl;
    return;
  }

  data[used++] = num;
}

bool ArrayData::full() const {
  return this->capacity == this->used;
}

void ArrayData::emptyArray() {
  this->used = 0;
}
void ArrayData::showData() const {
  for (size_t i = 0; i < used; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

// 배열 연산자
double& ArrayData::operator[](size_t num) {
  if (num >= 0 && num < capacity) {
    return data[num];
  } else {
    cout << "배열 참조 오류" << endl;
    exit(0);
  }
}
const double& ArrayData::operator[](size_t num) const {
  if (num >= 0 && num < capacity) {
    return data[num];
  } else {
    cout << "배열 참조 오류" << endl;
    exit(0);
  }
}

//대입 연산자
ArrayData& ArrayData::operator=(const ArrayData &rhs) {
  if (this == &rhs) {
    return *this;
  }
  this->capacity = rhs.capacity;
  this->used = rhs.used;
  data.reset(new double[capacity]); // smart_ptr인 경우
  // if (data != nullptr) { // smart_ptr이 아닌경우.
  //   delete[] data;
  // }
  // data = new double[capacity];
  for (size_t i = 0; i < used; i++)
  {
    data[i] = rhs.data[i];
  }
  return *this;
}
//이동대입
ArrayData& ArrayData::operator=(ArrayData &&rhs) noexcept {
  this->capacity = rhs.capacity;
  this->used = rhs.used;
  data = move(rhs.data); // smart_ptr인 경우
  // if (data != nullptr) { // smart_ptr이 아닌경우
  //   delete[] data;
  // }
  // data = rhs.data;
  // rhs.data = nullptr;
  return *this;
}