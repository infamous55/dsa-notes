#include <stdexcept>

#include "linked-list.h"

template <typename T> LinkedList<T>::LinkedList() {
  head = nullptr;
  size = 0;
}

template <typename T> LinkedList<T>::LinkedList(const LinkedList<T> &other) {
  head = nullptr;
  size = 0;
  Node *current_node = other.head;
  while (current_node) {
    push_back(current_node->data);
    current_node = current_node->next;
  }
}

template <typename T> LinkedList<T>::~LinkedList() {
  Node *current_node = this->head;
  Node *next_node;
  while (current_node) {
    next_node = current_node->next;
    delete current_node;
    current_node = next_node;
  }
}

template <typename T>
const LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other) {
  head = other.head;
  size = other.size;
}

template <typename T> T &LinkedList<T>::operator[](int index) {
  if (index < 0 || index >= size)
    throw std::out_of_range("List index is out of range");
  int current_index = 0;
  Node *current_node = this->head;
  while (current_node) {
    if (current_index == index)
      return current_node->data;
    current_node = current_node->next;
    current_index++;
  }
  throw std::out_of_range("List index is out of range");
}

template <typename T> const T &LinkedList<T>::operator[](int index) const {
  if (index < 0 || index >= size)
    throw std::out_of_range("List index is out of range");
  int current_index = 0;
  Node *current_node = this->head;
  while (current_node) {
    if (current_index == index)
      return current_node->data;
    current_node = current_node->next;
    current_index++;
  }
  throw std::out_of_range("List index is out of range");
}

template <typename T> T &LinkedList<T>::at(int index) const {
  if (index < 0 || index >= size)
    throw std::out_of_range("List index is out of range");
  int current_index = 0;
  Node *current_node = this->head;
  while (current_node) {
    if (current_index == index)
      return current_node->data;
    current_node = current_node->next;
    current_index++;
  }
  throw std::out_of_range("List index is out of range");
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &other) const {
  if (this->size != other.size)
    return false;
  Node *current_node = this->head, other_current_node = other.head;
  while (current_node) {
    if (current_node != other_current_node)
      return false;
    current_node = current_node->next;
    other_current_node = other_current_node.next;
  }
  return true;
}

template <typename T>
bool LinkedList<T>::operator!=(const LinkedList<T> &other) const {
  if (this->size != other.size)
    return true;
  Node *current_node = this->head, other_current_node = other.head;
  while (current_node) {
    if (current_node == other_current_node)
      return false;
    current_node = current_node->next;
    other_current_node = other_current_node.next;
  }
  return true;
}

template <typename T> void LinkedList<T>::push_front(const T &data) {
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = this->head;
  this->head = new_node;
  this->size++;
}

template <typename T> void LinkedList<T>::pop_front() {
  if (this->size == 0)
    throw std::out_of_range("List is empty");
  Node *new_head = this->head->next;
  delete this->head;
  this->head = new_head;
  this->size--;
}

template <typename T> void LinkedList<T>::push_back(const T &data) {
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = nullptr;
  if (this->head == nullptr) {
    this->head = new_node;
  } else {
    Node *current_node = this->head;
    while (current_node->next) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
  this->size++;
}

template <typename T> void LinkedList<T>::pop_back() {
  if (this->size == 0)
    throw std::out_of_range("List is empty");
  if (this->size == 1) {
    delete this->head;
    this->head = nullptr;
  } else {
    Node *current_node = this->head;
    while (current_node->next->next) {
      current_node = current_node->next;
    }
    delete current_node->next;
    current_node->next = nullptr;
  }
  this->size--;
}

template <typename T> bool LinkedList<T>::empty() const {
  return this->size == 0;
}

template <typename T> int LinkedList<T>::length() const { return this->size; }