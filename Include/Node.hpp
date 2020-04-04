#include <memory>

template <class T>
class Node
{
public:
    T value;
    std::shared_ptr<Node<T>> next;

    Node(T _value)
    {
        value = _value;
        next = nullptr;
    }
};
