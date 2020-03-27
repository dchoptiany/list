template <class T>
class Node
{
public:
    T value;
    Node* next;

    Node() = default;
    Node(T _value)
    {
        value = _value;
        next = nullptr;
    }
};