#include <vector>
#include <iostream>
#include "Node.h"

template <class T>
class List
{
public:
    Node<T>* first;

    List()
    {
        first = nullptr;
    }

    void push_back(T _value)
    {
        Node<T> newNode(_value);

        Node<T>* current = first;

        while(current -> next != nullptr)
        {
            current = current -> next;
        }

        current -> next = &newNode;
    }

    void print()
    {
        Node<T>* current = first;
        std::string result;

        while(current != nullptr)
        {
            result += current->value;

            if(current->next != nullptr)
            {
                result += ", ";
            }

            current = current->next;
        }

        std::cout << result;
    }

    unsigned int size()
    {
        unsigned int counter = 0;

        Node<T>* current = first;

        while(current != nullptr)
        {
            ++counter;
            current = current -> next;
        }

        return counter;
    }
};