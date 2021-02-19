#include <stdio.h>
#include <math.h>
#include <iostream>

int findComplement(int num)
{
    if (num == 0)
    {
        return 1;
    }

    unsigned mask = ~0;
    while (num & mask)
    {
        mask <<= 1;
    }
    return ~mask & ~num;
}

// int main()
// {
//     std::cout << "Number Complement" << std::endl;
//     std::cout << findComplement(7) << std::endl; // 0
//     std::cout << findComplement(5) << std::endl; // 2
//     std::cout << findComplement(2147483647) << std::endl; // 0
//     std::cout << findComplement(0) << std::endl; // 1
// }