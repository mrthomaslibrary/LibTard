template <typename T>
class Node {
  public:
  T data;
  Node *nextNode;
  Node<T>(T newData);
  ~Node();
  T getData();
};
