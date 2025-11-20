#pragma once
#include <string>
#include "Product.h"
#include <vector>
#include <memory>

using std::string;
using std::unique_ptr;
using std::vector;

class Customer {
	private:
		string m_name;
		int m_number=0;
		int m_count = 0;
		// Product **items;
		// vector의 경우 이미 가변 배열을 하나 선언한 것. 생성자에서 items 배열 생성할 필요 없음
		vector<unique_ptr<Product>> items; 

	public:
		Customer(const string& name, const int& number);
		~Customer();			

		string getName() const;
		int getCount() const;
		void showlist() const;
		void showTVList() const;
		void showVegetableList() const;

		//구현
		void buy(unique_ptr<Product> item); // 살때마다 제품 저장. 제품 살때 제품의 원 정보 사라지면 안됨. 동적 바인딩
};

// 저장 구조 선언, buy 함수. TV, vegitavle 살때