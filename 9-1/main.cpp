#include <iostream>
#include "DocWriter.h"

using namespace std;

int main(void) {
  DocWriter doc("test.txt", "greenjoa");
  doc.write();

  return 0;
}