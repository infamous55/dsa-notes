#include <cstdlib>
#include <iostream>

#include "array.cpp"
#include "array.h"

int main() {
  Array<int> arr(10);

  for (int i = 0; i < 10; i++)
    arr[i] = i;

  std::cout << arr[1] << ' ';

  Array<int> second_arr(5);
  second_arr = arr;

  std::cout << second_arr.length() << ' ';

  if (second_arr == arr)
    std::cout << "It works!";

  return EXIT_SUCCESS;
}