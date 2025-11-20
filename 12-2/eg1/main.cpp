#include <iostream>
#include "Customer.h"
#include "Product.h"
#include "TV.h"
#include "Vegetable.h"

using namespace std;

int main(void) {
  Customer c1("c1", 10);

  c1.buy(make_unique<TV>("건국TV", 100, 20));
  c1.buy(make_unique<TV>("대학TV", 100, 40));
  c1.buy(make_unique<Vegetable>("시금치", 50, "남해", 5));
  c1.buy(make_unique<TV>("세종TV", 100, 15));

  c1.showTVList();
  cout << endl;
  c1.showVegetableList();

  return 0;
}