#ifndef LIST
#define LIST

#include <iostream>
#include <stdexcept>
#include "Node.hpp"

template <class T> class List;
template <class T> std::ostream& operator<<(std::ostream&, const List<T>&);

template <class T>
class List
{
public:
    std::shared_ptr<Node<T>> first;

    List();
    List(const std::initializer_list<T>&);
    List(const List<T>&);
    void push_front(T);
    void push_back(T);
    void insert(size_t, T);
    void pop_front();
    void pop_back();
    void erase(size_t);
    void clear();
    void print();
    bool empty();
    size_t size();
    T& front();
    T& back();
    T& at(size_t);
    T min();
    T max();
    void remove(T);
    void merge(List<T>&);
    void assign(size_t, T);
    void swap(List<T>&);
    T& operator[](size_t);
    bool operator==(List<T>&);
    List<T>& operator=(const List<T>&);
    List<T>& operator=(const std::initializer_list<T>&);
    friend std::ostream& operator<< <T>(std::ostream&, const List<T>&);
};

template <class T>
List<T>::List()
{
    first = nullptr;
}

template <class T>
List<T>::List(const std::initializer_list<T>& args)
{
    first = std::make_shared<Node<T>>(Node<T>(*args.begin()));
    auto current = first;

    for(auto it = args.begin() + 1; it != args.end(); ++it)
    {
        current -> next = std::make_shared<Node<T>>(Node<T>(*it));
        current = current -> next;
    }
}

template <class T>
List<T>::List(const List<T>& list)
{
    std::shared_ptr<Node<T>> current = list.first;

    while(current != nullptr)
    {
        push_back(current->value);
        current = current->next;
    }
}

template <class T>
void List<T>::push_front(const T _value)
{
    auto newNode = std::make_shared<Node<T>>(Node<T>(_value));

    if(first != nullptr)
    {
        newNode -> next = first;
    }

    first = newNode;
}

template <class T>
void List<T>::push_back(const T _value)
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

template <class T>
void List<T>::insert(const size_t pos, const T _value)
{
    if(pos > size())
    {
        throw std::out_of_range("Index out of range");
    }

    if(pos == 0)
    {
        push_front(_value);
        return;
    }

    if(pos == size())
    {
        push_back(_value);
        return;
    }

    auto newNode = std::make_shared<Node<T>>(Node<T>(_value));

    size_t index = 0;
    std::shared_ptr<Node<T>> current = first;

    while(index < pos - 1)
    {
        current = current -> next;
        ++index;
    }

    newNode -> next = current -> next;
    current -> next = newNode;
}

template <class T>
void List<T>::pop_front()
{
    if(first == nullptr)
    {
        return;
    }

    if(first -> next == nullptr)
    {
        first = nullptr;
        return;
    }

    std::shared_ptr<Node<T>> second = first -> next;
    first = second;
}

template <class T>
void List<T>::pop_back()
{
    if(first == nullptr)
    {
        return;
    }

    if(first -> next == nullptr)
    {
        first = nullptr;
        return;
    }

    std::shared_ptr<Node<T>> current = first;

    while(current -> next -> next != nullptr)
    {
        current = current -> next;
    }

    current -> next = nullptr;
}

template <class T>
void List<T>::erase(const size_t pos)
{
    if(pos >= size())
    {
        throw std::out_of_range("Index out of range");
    }

    if(pos == 0)
    {
        pop_front();
        return;
    }

    if(pos == size() - 1)
    {
        pop_back();
        return;
    }

    size_t index = 0;
    std::shared_ptr<Node<T>> current = first;

    while(index < pos - 1)
    {
        current = current -> next;
        ++index;
    }

    current -> next = current -> next -> next;
}

template <class T>
void List<T>::clear()
{
    if(!empty())
    {
        first = nullptr;
    }
}

template <class T>
void List<T>::print()
{
    std::shared_ptr<Node<T>> current = first;

    while(current != nullptr)
    {
        std::cout << current -> value << " ";
        current = current -> next;
    }
}

template <class T>
bool List<T>::empty()
{
    return first == nullptr;
}

template <class T>
size_t List<T>::size()
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

template <class T>
T& List<T>::front()
{
    if(first == nullptr)
    {
        throw std::invalid_argument("List is empty");
    }

    return first -> value;
}

template <class T>
T& List<T>::back()
{
    if(first == nullptr)
    {
        throw std::invalid_argument("List is empty");
    }

    std::shared_ptr<Node<T>> current = first;

    while(current -> next != nullptr)
    {
        current = current -> next;
    }

    return current -> value;
}

template <class T>
T& List<T>::at(const size_t pos)
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

template <class T>
T List<T>::min()
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

template <class T>
T List<T>::max()
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

template <class T>
void List<T>::remove(const T _value)
{
    size_t index = 0;

    while(index < size())
    {
        if(at(index) == _value)
        {
            erase(index);
        }
        else
        {
            ++index;
        }
    }
}

template <class T>
void List<T>::merge(List<T>& list)
{
    for(size_t i = 0; i < list.size(); i++)
    {
        push_back(list.at(i));
    }
}

template <class T>
void List<T>::assign(const size_t count, const T value)
{
    clear();

    for(size_t i = 0; i < count; i++)
    {
        push_back(value);
    }
}

template <class T>
void List<T>::swap(List<T>& rhs)
{
    std::shared_ptr<Node<T>> temp = rhs.first;
    rhs.first = first;
    first = temp;
}

template <class T>
T& List<T>::operator[](const size_t pos)
{
    return at(pos);
}
template <class T>
bool List<T>::operator==(List<T>& rhs)
{
    if(size() != rhs.size())
    {
        return false;
    }

    for(size_t i = 0; i < size(); i++)
    {
        if(this -> at(i) != rhs.at(i))
        {
            return false;
        }
    }

    return true;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& rhs)
{
    if(this != &rhs)
    {
        clear();

        std::shared_ptr<Node<T>> current = rhs.first;

        while(current != nullptr)
        {
            push_back(current -> value);
            current = current -> next;
        }
    }

    return *this;
}

template <class T>
List<T>& List<T>::operator=(const std::initializer_list<T>& args)
{
    clear();

    for(auto it = args.begin(); it != args.end(); ++it)
    {
        push_back(*it);
    }

    return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& list)
{
    std::shared_ptr<Node<T>> current = list.first;

    while(current != nullptr)
    {
        os << current -> value << " ";
        current = current -> next;
    }

    return os;
}

#endif
