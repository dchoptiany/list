#include <iostream>
#include "Include/List.hpp"

int main()
{
    List<int> myList {1, 2, 3, 5};
    List<int> secondList = {6, 7, 8};
    myList.push_front(0);
    secondList.push_back(9);
    myList.insert(4, 4);
    myList.pop_front();
    secondList.pop_back();
    myList.erase(1);
    myList.print();
    std::cout << secondList.size() << std::endl;
    myList.front() = 4;
    std::cout << secondList.back() << std::endl;
    std::cout << myList.empty() << std::endl;
    std::cout << myList.min() << std::endl;
    std::cout << secondList.max() << std::endl;
    secondList.clear();
    myList.at(3) = 8;
    myList.remove(8);
    secondList.merge(myList);
    myList.assign(10, 0);
    secondList[2] = 9;
    std::cout << (myList == secondList) << std::endl;
    secondList = {1, 2, 3};
    myList = secondList;
    std::cout << secondList << std::endl;
}
