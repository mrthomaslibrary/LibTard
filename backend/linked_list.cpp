#include "linked_list.hpp"

template <typename T> LinkedList<T>::LinkedList() { rootNode = nullptr; }

template <typename T> LinkedList<T>::~LinkedList() {}

template <typename T> void LinkedList<T>::insertData(T newData) {
  Node<T> *newNode = new Node<T>(newData);
  if (!rootNode) {
    rootNode = newNode;
    return;
  }
  Node<T> *currentNode = rootNode;
  while (currentNode->nextNode) {
    currentNode = currentNode->nextNode;
  }
  currentNode->nextNode = newNode;
  return;
}

template <typename T> Node<T>* LinkedList<T>::getData(int n) {
  if (!rootNode) { return; }
  Node<T> *currentNode = rootNode;
  for (int i = 0; i < n; i++) {
    currentNode = currentNode->nextNode;
  }
  return currentNode;
}

template <typename T> void LinkedList<T>::deleteNode(int n) {
  if (!rootNode) { return; }
  Node<T> *currentNode = rootNode;
  if (0 == n) {
    rootNode = currentNode->nextNode;
    delete currentNode;
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    currentNode = currentNode->nextNode;
  }
  Node<T> *tempNode = currentNode->nextNode;
  currentNode->nextNode = tempNode->nextNode;
  delete tempNode;
  return;  
}
