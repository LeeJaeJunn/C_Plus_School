#include "Product.h"
#include <iostream>
using namespace std;
Product::Product(const string& name, const int& price)
	:m_name(name), m_price(price)
{
}

Product::~Product() {
}

int Product::getPrice() const {
	return m_price;
}

string Product::getName() const {
	return m_name;
}

void Product::show() const {
	cout << "-------------------------------" << endl;
	cout << "제품명 : " << m_name << endl;
	cout << "제품가격 : " << m_price << endl;	
}
