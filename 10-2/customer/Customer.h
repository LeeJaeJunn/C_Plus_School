#pragma once
#include <string>
#include "Product.h"

using std::string;

class Customer {
	private:
		string m_name;
		int m_number=0;
		int m_count = 0;
		Product **buying;

	public:
		Customer(const string& name, const int& number);
		~Customer();			

		string getName() const;
		int getCount() const;
		void showlist() const;
		void showTVList() const;
		void showVegetableList() const;

		//구현
		void buy(Product *product); // 살때마다 제품 저장. 제품 살때 제품의 원 정보 사라지면 안됨. 동적 바인딩
};

// 저장 구조 선언, buy 함수. TV, vegitavle 살때