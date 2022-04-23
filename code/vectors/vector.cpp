#include <cstdlib>
#include <stdexcept>

#include "vector.h"

#define INITIAL_CAPACITY 4

template <typename T> Vector<T>::Vector() {
  this->capacity = INITIAL_CAPACITY;
  this->size = 0;
  ptr = (T *)malloc(sizeof(T) * capacity);
  if (!ptr)
    throw std::bad_alloc();
}

template <typename T> Vector<T>::Vector(const Vector<T> &other) {
  this->capacity = other.capacity;
  this->size = other.size;
  free(ptr);
  ptr = (T *)malloc(sizeof(T) * capacity);
  for (int i = 0; i < size; i++)
    ptr[i] = other.ptr[i];
}

template <typename T> Vector<T>::~Vector() {
  this->size = 0;
  this->capacity = 0;
  free(ptr);
}

template <typename T>
const Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
  if (&other != this) {
    this->capacity = other.capacity;
    this->size = other.size;
    free(ptr);
    ptr = (T *)malloc(sizeof(T) * capacity);
    for (int i = 0; i < size; i++)
      ptr[i] = other.ptr[i];
  }
  return *this;
}

template <typename T> T &Vector<T>::operator[](int index) {
  if (index < 0 || index >= size)
    throw std::out_of_range("Vector index is out of range");
  return ptr[index];
}

template <typename T> const T &Vector<T>::operator[](int index) const {
  if (index < 0 || index >= size)
    throw std::out_of_range("Vector index is out of range");
  return ptr[index];
}

template <typename T> int Vector<T>::at(int index) const {
  if (index < 0 || index >= size)
    throw std::out_of_range("Vector index is out of range");
  return ptr[index];
}

template <typename T> void Vector<T>::set(int index, T value) {
  if (index < 0 || index >= size)
    throw std::out_of_range("Vector index is out of range");
  ptr[index] = value;
}

template <typename T> void Vector<T>::insert_at(int index, T value) {
  if (index < 0 || index >= size)
    throw std::out_of_range("Vector index is out of range");
  if (size == capacity)
    resize(capacity * 2);
  for (int i = size - 1; i >= index; i--)
    ptr[i + 1] = ptr[i];
  ptr[index] = value;
  size++;
}

template <typename T> void Vector<T>::delete_at(int index) {
  if (index < 0 || index >= size)
    throw std::out_of_range("Vector index is out of range");
  for (int i = index; i < size - 1; i++)
    ptr[i] = ptr[i + 1];
  size--;
}

template <typename T> void Vector<T>::remove(T value) {
  for (int i = 0; i < size; i++)
    if (ptr[i] == value) {
      for (int j = i; j < size - 1; j++)
        ptr[j] = ptr[j + 1];
      size--;
    }
}

template <typename T> void Vector<T>::clear() {
  this->capacity = INITIAL_CAPACITY;
  this->size = 0;
  ptr = (T *)malloc(sizeof(T) * capacity);
}

template <typename T> void Vector<T>::push_back(T value) {
  if (size == capacity)
    resize(capacity * 2);
  ptr[size] = value;
  size++;
}

template <typename T> void Vector<T>::pop_back() {
  if (size == 0)
    throw std::out_of_range("Vector is empty");
  size--;
}

template <typename T> void Vector<T>::push_front(T value) {
  if (size == capacity)
    resize(capacity * 2);
  for (int i = size; i > 0; i--)
    ptr[i] = ptr[i - 1];
  ptr[0] = value;
  size++;
}

template <typename T> void Vector<T>::pop_front() {
  if (size == 0)
    throw std::out_of_range("Vector is empty");
  for (int i = 0; i < size - 1; i++)
    ptr[i] = ptr[i + 1];
  size--;
}

template <typename T> bool Vector<T>::contains(T value) const {
  for (int i = 0; i < size; i++)
    if (ptr[i] == value)
      return true;
  return false;
}

template <typename T> int Vector<T>::find(T value) const {
  for (int i = 0; i < size; i++)
    if (ptr[i] == value)
      return i;
  return -1;
}

template <typename T> int Vector<T>::length() const { return size; }

template <typename T> bool Vector<T>::empty() const { return size == 0; }

template <typename T> bool Vector<T>::operator==(const Vector<T> &other) const {
  if (size != other.size)
    return false;
  for (int i = 0; i < size; i++)
    if (ptr[i] != other.ptr[i])
      return false;
  return true;
}

template <typename T> bool Vector<T>::operator!=(const Vector<T> &other) const {
  return !(*this == other);
}

template <typename T> void Vector<T>::resize(int new_capacity) {
  this->capacity = new_capacity;
  ptr = (T *)realloc(ptr, capacity * sizeof(T));
}