#pragma once
class ArrayData
{
private:			
	double* data=nullptr;
	int capacity;
	int used;	
public:
	ArrayData();	
	ArrayData(const int& capacity);
	~ArrayData();
	void addElement(const double& num);
	bool full() const;
	void emptyArray();
	void showData() const;	
	int getCapacity() const {
		return this->capacity;
	};
	int getUsed() const {
		return this->used;
	};
};

