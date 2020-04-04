#include <iostream>
#include "Include/List.hpp"

int main()
{
    List<int> newIntList;

    for(int i = 0; i < 10; i++)
    {
        newIntList.push_back(i);
    }

    newIntList.push_front(-1);

    std::cout << "Size of newIntList: " << newIntList.size() << std::endl;

    std::cout << "newIntList.empty(): " << newIntList.empty()  << std::endl;

    std::cout << "newIntList.print(): ";
    newIntList.print();

    newIntList.pop_front();

    std::cout << std::endl << "newIntList.print() after pop_front(): ";
    newIntList.print();

    newIntList.pop_back();

    std::cout << std::endl << "newIntList.print() after pop_back(): ";
    newIntList.print();

    std::cout << std::endl << "newIntList.min(): " << newIntList.min();

    std::cout << std::endl << "newIntList.max(): " << newIntList.max();

    std::cout << std::endl << std::endl;

    List<std::string> newStringList;

    newStringList.push_back("one");
    newStringList.push_back("two");
    newStringList.push_back("three");
    newStringList.push_back("four");
    newStringList.push_back("five");

    newStringList.push_front("zero");

    std::cout << "Size of newStringList: " << newStringList.size() << std::endl;

    std::cout << "newStringList.empty(): " << newStringList.empty() << std::endl;

    std::cout << "newStringList.print(): ";
    newStringList.print();

    newStringList.pop_front();

    std::cout << std::endl << "newStringList.print() after pop_front(): ";
    newStringList.print();

    newStringList.pop_back();

    std::cout << std::endl << "newStringList.print() after pop_back(): ";
    newStringList.print();

    std::cout << std::endl << std::endl;

    List<double> emptyDoubleList;

    std::cout << "emptyDoubleList.empty(): " << emptyDoubleList.empty() << std::endl;
}
