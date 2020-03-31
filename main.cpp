#include <iostream>
#include "List.h"

int main()
{
    List<int> newIntList;

    for(int i = 0; i < 10; i++)
    {
        newIntList.push_back(i);
    }

    newIntList.push_front(-1);

    std::cout << "Size of newIntList: " << newIntList.size() << std::endl;

    std::cout << "newIntList.print(): ";
    newIntList.print();

    newIntList.pop_front();

    std::cout << std::endl << "newIntList.print() after pop_front(): ";
    newIntList.print();

    std::cout << std::endl << std::endl;

    List<std::string> newStringList;

    newStringList.push_back("one");
    newStringList.push_back("two");
    newStringList.push_back("three");
    newStringList.push_back("four");
    newStringList.push_back("five");

    newStringList.push_front("zero");

    std::cout << "Size of newStringList: " << newStringList.size() << std::endl;

    std::cout << "newStringList.print(): ";
    newStringList.print();

    newStringList.pop_front();

    std::cout << std::endl << "newStringList.print() after pop_front(): ";
    newStringList.print();
}
