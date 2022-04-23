#include <cstddef>
#include <stdexcept>

#include "array.h"

template <typename T> Array<T>::Array(int size) {
  ptr = new T[size];
  this->size = size;
}

template <typename T> Array<T>::Array(const Array<T> &other) {
  this->size = other.size;
  ptr = new T[size];
  for (int i = 0; i < size; i++)
    ptr[i] = other.ptr[i];
}

template <typename T> Array<T>::~Array() {
  size = 0;
  delete[] ptr;
  ptr = NULL;
}

template <typename T>
const Array<T> &Array<T>::operator=(const Array<T> &other) {
  if (&other != this) {
    delete[] ptr;
    this->size = other.size;
    ptr = new T[size];
    for (int i = 0; i < size; i++)
      ptr[i] = other.ptr[i];
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](int index) {
  if (index < 0 || index >= size)
    throw std::out_of_range("Array index is out of range");
  return ptr[index];
}

template <typename T> const T &Array<T>::operator[](int index) const {
  if (index < 0 || index >= size)
    throw std::out_of_range("Array index is out of range");
  return ptr[index];
}

template <typename T> bool Array<T>::operator==(const Array<T> &other) const {
  if (size != other.size)
    return false;
  for (int i = 0; i < size; i++)
    if (ptr[i] != other.ptr[i])
      return false;
  return true;
}

template <typename T> bool Array<T>::operator!=(const Array<T> &other) const {
  return (*this != other);
}

template <typename T> int Array<T>::length() const { return this->size; }