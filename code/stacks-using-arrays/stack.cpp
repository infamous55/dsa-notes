#include <cstdlib>
#include <stdexcept>

#include "stack.h"

#define INITIAL_CAPACITY 4

template <typename T> Stack<T>::Stack() {
  this->size = 0;
  this->capacity = INITIAL_CAPACITY;
  this->ptr = new T[INITIAL_CAPACITY];
};

template <typename T> Stack<T>::Stack(const Stack<T> &other) {
  this->capacity = other.capacity;
  this->size = other.size;
  delete ptr;
  ptr = new T[capacity];
  for (int i = 0; i < size; i++)
    ptr[i] = other.ptr[i];
};

template <typename T> Stack<T>::~Stack() {
  this->size = 0;
  this->capacity = 0;
  delete ptr;
};

template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
  if (&other != this) {
    this->capacity = other.capacity;
    this->size = other.size;
    delete ptr;
    ptr = new T[capacity];
    for (int i = 0; i < size; i++)
      ptr[i] = other.ptr[i];
  }
  return *this;
};

template <typename T> bool Stack<T>::operator==(const Stack<T> &other) const {
  if (this->size != other.size)
    return false;
  for (int i = 0; i < size; i++)
    if (this->ptr[i] != other.ptr[i])
      return false;
  return true;
};

template <typename T> bool Stack<T>::operator!=(const Stack<T> &other) const {
  return !(*this == other);
};

template <typename T> void Stack<T>::push(T item) {
  if (size == capacity)
    resize(capacity * 2);
  ptr[size] = item;
  size++;
};

template <typename T> void Stack<T>::pop() {
  if (size == 0)
    throw std::out_of_range("Stack is empty");
  size--;
};

template <typename T> T Stack<T>::top() const {
  if (size == 0)
    throw std::out_of_range("Stack is empty");
  return ptr[size - 1];
};

template <typename T> int Stack<T>::length() const { return size; };

template <typename T> bool Stack<T>::empty() const { return size == 0; };

template <typename T> void Stack<T>::resize(int new_capacity) {
  T *new_ptr = new T[new_capacity];
  for (int i = 0; i < size; i++)
    new_ptr[i] = ptr[i];
  delete ptr;
  ptr = new_ptr;
  capacity = new_capacity;
};