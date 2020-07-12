#include <iostream>
#include "Include/List.hpp"

int main()
{
    List<int> newList {1, 2, 3, 4, 5};
    newList.push_back(6);
    newList.push_front(0);
    newList.pop_front();
    newList.pop_back();
    std::cout << "newList.print(): ";
    newList.print();
    newList.at(3) = 0;
    std::cout << std::endl << "newList.at(3): " << newList.at(3) << std::endl;
    std::cout << "newList size: " << newList.size() << std::endl;
    std::cout << std::boolalpha << "newList empty: " << newList.empty() << std::endl;
    std::cout << "newList begin: " << newList.begin() << std::endl;
    std::cout << "newList min: " << newList.min() << std::endl;
    std::cout << "newList max: " << newList.max() << std::endl;
    newList.insert(1, -1);
    newList.erase(1);
    std::cout << "std::cout << newList: " << newList << std::endl;
    newList.clear();
}
