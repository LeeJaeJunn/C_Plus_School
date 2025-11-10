#include <iostream>
#include "Customer.h"
#include "Product.h"
#include "TV.h"
#include "Vegetable.h"

using namespace std;

int main(void) {
  Customer c1("c1", 10);

  c1.buy(new Vegetable("양파", 100, "한국", 10));
  c1.buy(new TV("티비", 100, 100));

  // c1.showlist();

  c1.showTVList();
  c1.showVegetableList();

  return 0;
}