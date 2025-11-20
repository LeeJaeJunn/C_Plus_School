#include "Customer.h"
#include "TV.h"
#include "Vegetable.h"
#include <iostream>

using namespace std;

Customer::Customer(const string& name, const int& number)
	:m_name(name), m_number(number)
{}

Customer::~Customer() {
}

string Customer::getName() const
{
	return m_name;
}

int Customer::getCount() const
{
	return items.size();
}

void Customer::showlist() const {
	int price = 0;
	cout << "고객이름 : " << m_name << endl;
	cout << "구매개수 : " << items.size() << endl;
	for (auto it = items.begin(); it != items.end(); it++) {
		(*it)->show();
		price += (*it)->getPrice();
	}
		cout << "총합: " << price << endl;
}

void Customer::showTVList() const {
	for (int i = 0; i < items.size(); i++) {
		TV *tv = dynamic_cast<TV *>(items[i].get());
		if (tv != nullptr) {
			items[i]->show();
		}
	}
}
void Customer::showVegetableList() const {
	for (size_t i = 0; i < items.size(); i++) {
		Vegetable *vg = dynamic_cast<Vegetable *>(items[i].get());
		if (vg != nullptr) {
			items[i]->show();
		}
	}
}

void Customer::buy(unique_ptr<Product> item) {
	items.push_back(move(item));
}