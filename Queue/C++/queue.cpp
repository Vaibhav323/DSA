#include "queue_c.hpp"
#include <iostream>

int main() {
  queue<int> q(5);
  q.enQueue(1);
  q.enQueue(3);
  q.enQueue(7);
  q.enQueue(5);
  q.enQueue(10);

  std::cout << "Size of queue: " << q.size() << std::endl;

  std::cout << "Front Element: " << q.frontElement() << std::endl;
  std::cout << "Rear Element: " << q.rearElement() << std::endl;

  std::cout << "Dequeued element: " << q.deQueue() << std::endl;
  std::cout << "Dequeued element: " << q.deQueue() << std::endl;
  std::cout << "Dequeued element: " << q.deQueue() << std::endl;
  std::cout << "Dequeued element: " << q.deQueue() << std::endl;
  std::cout << "Dequeued element: " << q.deQueue() << std::endl;
  std::cout << "Dequeued element: " << q.deQueue() << std::endl;

  q.enQueue(15);
  q.enQueue(100);

  std::cout << "Size of queue: " << q.size() << std::endl;

  std::cout << "Front Element: " << q.frontElement() << std::endl;
  std::cout << "Rear Element: " << q.rearElement() << std::endl;

  return 0;
}

template <class T> queue<T>::queue() {
  capacity = 100;
  front = -1;
  rear = -1;
  limit = 0;
  array = new T[capacity];
}

template <class T> queue<T>::queue(size_q _cap) : capacity(_cap) {
  front = -1;
  rear = -1;
  limit = 0;
  array = new T[capacity];
}

template <class T> size_q queue<T>::size() { return limit; }

template <class T> T queue<T>::frontElement() { return array[front]; }

template <class T> T queue<T>::rearElement() { return array[rear]; }

template <class T> size_q queue<T>::isEmpty() { return (limit == 0); }

template <class T> size_q queue<T>::isFull() { return (limit == capacity); }

template <class T> void queue<T>::enQueue(T data) {
  if (isFull())
    std::cerr << "QUEUE OVERFLOW" << std::endl;
  else {
    rear = ++rear % capacity;
    array[rear] = data;
    if (front == -1)
      front = rear;
    ++limit;
  }
}

template <class T> size_q queue<T>::deQueue() {
  int data;
  if (isEmpty()) {
    std::cerr << "QUEUE IS EMPTY" << std::endl;
    return -1;
  }
  data = array[front];
  if (front == rear) {
    front = rear - 1;
    limit = 0;
  } else {
    front = ++front % capacity;
    --limit;
  }
  return data;
}

template <class T> queue<T>::~queue() {
  delete array;
  array = NULL;
}
