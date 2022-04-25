#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T> class LinkedList {
public:
  LinkedList();                           // constructor
  LinkedList(const LinkedList<T> &other); // copy constructor
  ~LinkedList();                          // destructor

  const LinkedList<T> &
  operator=(const LinkedList<T> &other); // assignment operator

  T &operator[](int index);             // index operator
  const T &operator[](int index) const; // index operator

  T &at(int index) const; // returns the value at the given index

  void push_front(const T &data); // add to front
  void pop_front();               // remove from front

  void push_back(const T &data); // add to back
  void pop_back();               // remove from back

  void insert_at(int index, const T &data); // insert at index
  void delete_at(int index);          // delete at index

  void reverse();     // reverse the list
  void print() const; // print the list

  bool empty() const; // returns true if the list is empty
  int length() const; // returns the size of the list

  bool operator==(const LinkedList<T> &other) const; // equality operator
  bool operator!=(const LinkedList<T> &other) const; // inequality operator
private:
  struct Node {
    T data;
    Node *next;
  };

  Node *head;
  int size;
};

#endif /* LINKED_LIST_H */