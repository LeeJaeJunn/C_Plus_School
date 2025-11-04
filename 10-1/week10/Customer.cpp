#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(const string& name, const int& number)
	:m_name(name), m_number(number), buying(new Product*[m_number])
{}

Customer::~Customer() {
	for (int i = 0; i < m_count; i++) {
		delete buying[i];
	}
	delete[] buying;
	buying = nullptr;
}

string Customer::getName() const
{
	return m_name;
}

int Customer::getCount() const
{
	return m_count;
}

void Customer::showlist() const {
	cout << "고객이름 : " << m_name << endl;
	cout << "구매개수 : " << m_count << endl;
	for (int i = 0; i < m_number; i++) {
		buying[i]->show();
	}
}

void Customer::buy(Product *product) {
	buying[m_count++] = product;
}