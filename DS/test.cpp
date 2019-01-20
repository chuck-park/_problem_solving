// LinkedList

#include <cstdio>

template<typename T>
class Node {
public:
  T value;
  Node<T> *next;
  Node():next(nullptr){} 
};

template<typename T>
class LinkedList {
public:
  int size;
  Node<T> head;
  LinkedList():size(0), head(nullptr){}
  LinkedList(Node<T> *next):head(next){}
};


