#include "linked_list_node.hpp"

template <typename T>
class LinkedList {
private:
 Node<T> *rootNode;
public:
  LinkedList();
  ~LinkedList();
  void insertData(T newData);
  Node<T>* getData(int n);
  void deleteNode(int n);
};
