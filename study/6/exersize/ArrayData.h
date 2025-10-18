#pragma once
#include <memory>

using namespace std;

class ArrayData {
  private:
    // double *data;
    shared_ptr<double[]> data;
    int capacity;
    int used;

  public:
    ArrayData();
    ArrayData(const int &capacity, const int &used = 0);
    ArrayData(ArrayData &arr); // 복사생성자
    ArrayData(ArrayData &&arr) noexcept; // 이동생성자
    ~ArrayData();

    void addElement(const double &num);
    bool full() const;
    int getCapacity() const {
      return this->capacity;
    }
    int getUsed() const {
      return this->used;
    }
    void emptyArray();
    void showData() const;
    
    // 배열 연산자
    double &operator[](size_t num);
    const double &operator[](size_t num) const;
    //대입 연산자
    ArrayData &operator=(const ArrayData &rhs);
    //이동대입
    ArrayData &operator=(ArrayData &&rhs) noexcept;
};