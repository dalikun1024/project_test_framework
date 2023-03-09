#include "sum_integers.hpp"

int sum_integers(const int *integers, int length) {
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    sum += integers[i];
  }
  return sum;
}
