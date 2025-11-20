#pragma once
#include <string>
using std::string;
class Product
{
protected:
	string m_name;
	int m_price;
public:
	Product(const string& name, const int& price);
	virtual ~Product();
	virtual int getPrice() const=0; // 순수 가상함수 .cpp파일에 정의 X.
	string getName() const;
	virtual void show() const;
};

