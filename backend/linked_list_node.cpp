#include "linked_list_node.hpp"
#include "book.hpp"

template <typename T> Node<T>::Node(const T newData) : data(newData), nextNode(nullptr) {}

template <typename T> Node<T>::~Node() {}

template <typename T> T Node<T>::getData() { return data; }

template class Node<Book>;
