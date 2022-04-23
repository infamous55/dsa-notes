#ifndef ARRAY_H
#define ARRAY_H

template <typename T> class Array {
public:
  Array(int size);              // constructor
  Array(const Array<T> &other); // copy constructor
  ~Array();                     // destructor

  const Array<T> &operator=(const Array<T> &other); // assignment operator

  T &operator[](int index);             // index operator
  const T &operator[](int index) const; // index operator

  bool operator==(const Array<T> &other) const; // equality operator
  bool operator!=(const Array<T> &other) const; // inequality operator

  int length() const; // returns the size of the array
private:
  T *ptr;   // pointer to the array
  int size; // size of the array
};

#endif /* ARRAY_H */