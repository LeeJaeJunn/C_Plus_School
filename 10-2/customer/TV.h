#pragma once
#include "Product.h"
class TV: public Product {
private:
	int m_size;
public:
	TV(const string& name, const int& price, const int& size);
	virtual ~TV();
	int getPrice() const;
	void show() const;
};

