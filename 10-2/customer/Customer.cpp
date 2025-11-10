#include "Customer.h"
#include "TV.h"
#include "Vegetable.h"
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
	int price = 0;
	cout << "고객이름 : " << m_name << endl;
	cout << "구매개수 : " << m_count << endl;
	for (int i = 0; i < m_count; i++) {
		buying[i]->show();
		price += buying[i]->getPrice();
	}
	cout << "총합: " << price << endl;
}

void Customer::showTVList() const {
	for (int i = 0; i < m_count; i++) {
		if(typeid(*buying[i]) == typeid(TV)) {
			buying[i]->show();
		}
	}
}
void Customer::showVegetableList() const {
	for (int i = 0; i < m_count; i++) {
		if(typeid(*buying[i]) == typeid(Vegetable)) {
			buying[i]->show();
		}
	}
}

void Customer::buy(Product *product) {
	buying[m_count++] = product;
}