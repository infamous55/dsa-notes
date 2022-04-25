#ifndef VECTOR_H
#define VECTOR_H

template <typename T> class Vector {
public:
  Vector();                       // constructor
  Vector(const Vector<T> &other); // copy constructor
  ~Vector();                      // destructor

  const Vector<T> &operator=(const Vector<T> &other); // assignment operator

  T &operator[](int index);             // index operator
  const T &operator[](int index) const; // index operator

  int at(int index) const; // returns the value at the given index
  void set(int index, T value);       // sets the value at the given index

  void insert_at(int index, T value); // inserts the value at the given index
  void delete_at(int index); // removes the value at the given index

  void remove(T value);      // removes the value from the array
  void clear();              // removes all values from the array

  void push_back(T value); // adds the value to the end of the array
  void pop_back();         // removes the value from the end of the array

  void push_front(T value); // adds the value to the beginning of the array
  void pop_front();         // removes the value from the beginning of the array

  bool contains(T value) const; // returns true if the array contains the value
  int find(T value)
      const; // returns the index of the value, or -1 if it is not found

  bool empty() const; // returns true if the array is empty
  int length() const; // returns the size of the array

  bool operator==(const Vector<T> &other) const; // equality operator
  bool operator!=(const Vector<T> &other) const; // inequality operator
private:
  size_t size;                   // size of the array
  size_t capacity;               // capacity of the array
  T *ptr;                        // pointer to the array
  void resize(int new_capacity); // resizes the array to the given capacity
};

#endif /* VECTOR_H */