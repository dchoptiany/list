template <class T>
class Node
{
    T value;
    Node* next;

public:
    Node(T _value)
    {
        value = _value;
        next = nullptr;
    }
};