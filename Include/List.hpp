#include <iostream>
#include <optional>
#include <stdexcept>
#include "Node.hpp"

template <class T>
class List
{
public:
    std::shared_ptr<Node<T>> first;

    List()
    {
        first = nullptr;
    }

    List(const std::initializer_list<T>& args)
    {
        first = std::make_shared<Node<T>>(Node<T>(*args.begin()));
        auto current = first;

        for(auto it = args.begin() + 1; it != args.end(); ++it)
        {
            current -> next = std::make_shared<Node<T>>(Node<T>(*it));
            current = current -> next;
        }
    }

    void push_front(T _value)
    {
	    auto newNode = std::make_shared<Node<T>>(Node<T>(_value));

  	    if(first != nullptr)
        {
  		    newNode -> next = first;
        }

  	    first = newNode;
    }

    void push_back(T _value)
    {
        auto newNode = std::make_shared<Node<T>>(Node<T>(_value));

        if(first == nullptr)
        {
            first = newNode;
            return;
        }

        std::shared_ptr<Node<T>> current = first;

        while(current -> next != nullptr)
        {
            current = current -> next;
        }

        current -> next = newNode;
    }

    void pop_front()
    {
        if(first == nullptr)
        {
            return;
        }

        if(first -> next == nullptr)
        {
            first == nullptr;
            return;
        }

        std::shared_ptr<Node<T>> second = first -> next;
        first = second;
    }

    void pop_back()
    {
        if(first == nullptr)
        {
            return;
        }

        if(first -> next == nullptr)
        {
            first == nullptr;
            return;
        }

        std::shared_ptr<Node<T>> current = first;

        while(current -> next -> next != nullptr)
        {
            current = current -> next;
        }

        current -> next = nullptr;
    }

    void print()
    {
        std::shared_ptr<Node<T>> current = first;

        while(current != nullptr)
        {
            std::cout << current -> value << " ";
            current = current -> next;
        }
    }

    size_t size()
    {
        size_t counter = 0;

        std::shared_ptr<Node<T>> current = first;

        while(current != nullptr)
        {
            ++counter;
            current = current -> next;
        }

        return counter;
    }

    bool empty()
    {
        return first == nullptr;
    }

    T min()
    {
        if(!empty())
        {
            std::shared_ptr<Node<T>> current = first;
            T minimum = current -> value;

            while(current != nullptr)
            {
                if(current -> value < minimum)
                {
                    minimum = current -> value;
                }

                current = current -> next;
            }

            return minimum;
        }
        return 0;
    }

    T max()
    {
        if(!empty())
        {
            std::shared_ptr<Node<T>> current = first;
            T maximum = current -> value;

            while(current != nullptr)
            {
                if(current -> value > maximum)
                {
                    maximum = current -> value;
                }

                current = current -> next;
            }

            return maximum;
        }
        return 0;
    }

    void clear()
    {
        if(!empty())
        {
            first = nullptr;
        }
    }

    std::optional<T> at(const size_t pos)
    {
        if(pos >= size())
        {
            throw std::out_of_range("Index out of range");
        }

        size_t index = 0;
        std::shared_ptr<Node<T>> current = first;

        while(index < pos)
        {
            current = current -> next;
            ++index;
        }

        return current -> value;
    }
};
