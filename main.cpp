#include <iostream>
#include "Include/List.hpp"

int main()
{
    List<int> newList {1, 2, 3, 4, 5};
    newList.push_back(6);
    newList.push_front(0);
    newList.pop_front();
    newList.pop_back();
    newList.print();
    std::cout << std::endl << "newList size: " << newList.size() << std::endl;
    std::cout << std::boolalpha << "newList empty: " << newList.empty() << std::endl;
    std::cout << "newList min: " << newList.min() << std::endl;
    std::cout << "newList max: " << newList.max() << std::endl;

    newList.clear();
}
