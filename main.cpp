#include <iostream>
#include "List.h"

int main()
{
    List<int> newList;

    for(int i = 0; i < 10; i++)
    {
        newList.push_back(i);
    }

    std::cout << "Size of newList: " << newList.size() << std::endl;

    std::cout << "newList.print():" << std::endl;
    newList.print();

    return 0;
}
