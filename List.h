#include <vector>
#include "Node.h"

template <class T>
class List
{
    std::vector<Node<T>> elements;

public:
    List() = default;
};