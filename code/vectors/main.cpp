#include <iostream>
#include <cstdlib>

#include "vector.h"
#include "vector.cpp"

int main() {
  Vector<int> v, v2;

  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  v.pop_back();
  v.pop_back();
  v.pop_back();
  v.pop_back();

  v.push_front(-1);
  v.push_front(-2);
  v.push_front(-3);

  v.pop_front();

  v.set(0, -2);
  v.insert_at(0, -3);

  std::cout << v.at(0) << ' ' << v[1] << std::endl;

  v.remove(0);
  v.delete_at(0);

  v2 = v;
  v.clear();

  if (v != v2) {
    std::cout << v2.contains(1) << ' ' << v2.find(1) << std::endl;
  }

  if (v.empty()) {
    std::cout << v2.length() << std::endl;
  }

  return EXIT_SUCCESS;
}