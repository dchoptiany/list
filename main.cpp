#include <iostream>
#include "List.h"

int main()
{
    List<int> newList;

    newList.push_back(5);

    /*for(int i = 0; i < 10; i++)
    {
        newList.push_back(i);
    }*/

    std::cout << "Size of newList: " << newList.size() << std::endl;

    std::cout << "newList.print(): ";
    newList.print();

    return 0;
}
