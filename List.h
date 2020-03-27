#include <vector>
#include <iostream>
#include "Node.h"

template <class T>
class List
{
    std::vector<Node<T>> elements;

public:
    List() = default;

    void push_back(T _value)
    {
        Node<T> newNode(_value);
        elements.back().next = &newNode;
        elements.push_back(newNode);
    }

    void print()
    {
        for(const auto& element : elements)
        {
            std::cout << element.value << std::endl;
        }
    }

    unsigned int size()
    {
        return elements.size();
    }
};