#include <iostream>
#include "List.h"

int main()
{
    List<int> newList;

    for(int i = 0; i < 10; i++)
    {
        newList.push_back(i);
    }

    std::cout << "Size of lista: " << newList.size() << std::endl;

    std::cout << "lista.print():" << std::endl;
    newList.print();

    return 0;
}
