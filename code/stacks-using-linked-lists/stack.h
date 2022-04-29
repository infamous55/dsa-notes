#ifndef STACK_H
#define STACK_H

template <typename T> class Stack {
public:
  Stack();                      // constructor
  Stack(const Stack<T> &other); // copy constructor
  ~Stack();                     // destructor

  const Stack<T> &operator=(const Stack<T> &other); // assignment operator

  bool operator==(const Stack<T> &other) const; // equality operator
  bool operator!=(const Stack<T> &other) const; // inequality operator

  void push(T data); // adds an item to the top of the stack
  void pop();        // removes the top item from the stack
  T top() const;     // returns the top item from the stack

  int length() const; // returns the size of the stack
  bool empty() const; // returns true if the stack is empty
private:
  struct Node {
    T data;
    Node *next;
  };
  Node *head;
  int size;
};

#endif /* STACK_H */
