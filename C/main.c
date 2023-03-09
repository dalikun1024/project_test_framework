#include "sum_integers.h"


int main() {
  int integers[] = {1, 2, 3, 4, 5};

  if (sum_integers(integers, sizeof(integers)/sizeof(int)) == 15) {
    return 0;
  } else {
    return 1;
  }
}
