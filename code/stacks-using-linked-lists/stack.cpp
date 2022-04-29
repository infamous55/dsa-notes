#include <cstdlib>

#include "stack.h"

template <typename T> Stack<T>::Stack() {
  this->size = 0;
  this->head = nullptr;
};

template <typename T> Stack<T>::Stack(const Stack<T> &other) {
  this->size = other.size;
  this->head = nullptr;
  Node *current_node = this->head;
  Node *other_current_node = other.head;
  while (other_current_node) {
    Node *new_node = new Node();
    new_node->data = other_current_node->data;
    new_node->next = nullptr;
    if (this->head == nullptr) {
      this->head = new_node;
    } else {
      current_node->next = new_node;
    }
  }
};

template <typename T> Stack<T>::~Stack() {
  Node *current_node = this->head;
  Node *next_node;
  while (current_node) {
    next_node = current_node->next;
    delete current_node;
    current_node = next_node;
  }
};

template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
  this->size = other.size;
  this->head = other.head;
}

template <typename T> bool Stack<T>::operator==(const Stack<T> &other) const {
  if (this->size != other.size) {
    return false;
  }
  Node *current_node = this->head;
  Node *other_current_node = other.head;
  while (current_node) {
    if (current_node->data != other_current_node->data) {
      return false;
    }
    current_node = current_node->next;
    other_current_node = other_current_node->next;
  }
}

template <typename T> bool Stack<T>::operator!=(const Stack<T> &other) const {
  return !(*this == other);
}

template <typename T> void Stack<T>::push(T data) {
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = this->head;
  this->head = new_node;
  this->size++;
}

template <typename T> void Stack<T>::pop() {
  if (this->head) {
    Node *current_node = this->head;
    this->head = this->head->next;
    delete current_node;
    this->size--;
    return;
  }
  exit(EXIT_FAILURE);
}

template <typename T> T Stack<T>::top() const {
  if (this->head) {
    return this->head->data;
  }
  exit(EXIT_FAILURE);
}

template <typename T> int Stack<T>::length() const { return this->size; }

template <typename T> bool Stack<T>::empty() const { return this->size == 0; }