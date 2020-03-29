#include <iostream>
#include "List.h"

int main()
{
    List<int> newIntList;

    for(int i = 0; i < 10; i++)
    {
        newIntList.push_back(i);
    }

    std::cout << "Size of newIntList: " << newIntList.size() << std::endl;

    std::cout << "newList.print(): ";
    newIntList.print();

    std::cout << std::endl << std::endl;

    List<std::string> newStringList;

    newStringList.push_back("one");
    newStringList.push_back("two");
    newStringList.push_back("three");
    newStringList.push_back("four");
    newStringList.push_back("five");

    std::cout << "Size of newStringList: " << newStringList.size() << std::endl;

    std::cout << "newStringList.print(): ";
    newStringList.print();
}
