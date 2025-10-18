#include "ArrayData.h"
#include <iostream>

using namespace std;

ArrayData::ArrayData():ArrayData(3) {}
ArrayData::ArrayData(const int &capacity, const int &used):capacity(capacity), used(used) {
  cout << "생성자" << endl;
  // data = new double[this->capacity];
  data = make_unique<double[]>(this->capacity);
  // data = make_shared<double[]>(this->capacity);
}
ArrayData::ArrayData(ArrayData &arr):ArrayData(arr.capacity, arr.used) {
  cout << "복사생성자" << endl;
  for (size_t i = 0; i < used; i++) {
    data[i] = arr.data[i];
  }
}

ArrayData::ArrayData(ArrayData &&arr) noexcept :capacity(arr.capacity), used(arr.used), data(move(arr.data)) { // unique 포인터의 경우 move 함수 사용.
  cout << "이동생성자" << endl;
  // arr.data = nullptr;
}

ArrayData::~ArrayData() {
  // if (data != nullptr) {
  //   delete[] data;
  // }
  // data = nullptr;
}

void ArrayData::addElement(const double &num) {
  if (!full()) {
    data[used++] = num;
  } else {
    cout << "빈방이 없음\n";
  }
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


double &ArrayData::operator[](size_t num) {
  if (num >= 0 && num < capacity) {
    return data[num];
  } else {
    cout << "배열 참조 오류" << endl;
    exit(0);
  }
}
const double &ArrayData::operator[](size_t num) const {
  if (num >= 0 && num < capacity) {
    return data[num];
  } else {
    cout << "배열 참조 오류" << endl;
    exit(0);
  }
}

ArrayData& ArrayData::operator=(const ArrayData& rhs) {
  if (this == &rhs) {
    return *this;
  }
  this->capacity = rhs.capacity;
  this->used = rhs.used;
  data.reset(new double[capacity]);
  //data = static_cast<shared_ptr<double[]>>(new double[capacity]);
  for (size_t i = 0; i < used; i++) {
    data[i] = rhs.data[i];
  }
  return *this;
}

ArrayData& ArrayData::operator=(ArrayData&& rhs) noexcept {
  this->capacity = rhs.capacity;
  this->used = rhs.used;
  data = move(rhs.data);
  return *this;
}