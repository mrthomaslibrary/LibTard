#pragma once

template <typename T>
class Node {
  public:
  T data;
  Node *nextNode;
  Node<T>(const T newData);
  ~Node();
  T getData();
};
