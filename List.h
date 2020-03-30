#include <iostream>
#include "Node.h"

template <class T>
class List
{
public:
    //Node<T>* first;
    std::unique_ptr<Node<T>> first;

    List()
    {
        first = nullptr;
    }

    void push_back(T _value)
    {
        //Node<T>* newNode = new Node<T>(_value);
        std::unique_ptr<Node<T>> newNode = new Node<T>(_value);

        if(first == nullptr)
        {
            first = newNode;
            return;
        }

        std::unique_ptr<Node<T>> current = first;

        while(current -> next != nullptr)
        {
            current = current -> next;
        }

        current -> next = newNode;
    }

    void print()
    {
        std::unique_ptr<Node<T>> current = first;

        while(current != nullptr)
        {
            std::cout << current -> value << " ";
            current = current -> next;
        }
    }

    unsigned int size()
    {
        unsigned int counter = 0;

        std::unique_ptr<Node<T>> current = first;

        while(current != nullptr)
        {
            ++counter;
            current = current -> next;
        }

        return counter;
    }
};