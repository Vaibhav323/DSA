#include <iostream>

typedef int size_q;

template <class T> class queue {
private:
  T front, rear;
  size_q capacity, limit;
  T *array;

public:
  queue();
  queue(size_q capacity);
  size_q size();
  T frontElement();
  T rearElement();
  size_q isEmpty();
  size_q isFull();
  void enQueue(T data);
  size_q deQueue();
  ~queue();
};