#include "linked_list_node.hpp"

template <typename T> Node<T>::Node(T newData) { data = newData; }

template <typename T> Node<T>::~Node() {}

template <typename T> T Node<T>::getData() { return data; }
