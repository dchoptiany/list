#include <memory>

template <class T>
class Node
{
public:
    T value;
    //Node<T>* next;
    std::unique_ptr<Node<T>> next;

    Node(T _value)
    {
        value = _value;
        next = nullptr;
    }
};