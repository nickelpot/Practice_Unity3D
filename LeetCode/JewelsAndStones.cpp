#include <stdio.h>
#include <iostream>
#include <string>

int numJewelsInStones(std::string J, std::string S)
{
    int count = 0;
    for (const char& charJ : J)
    {
        size_t stone = 0;
        while (stone < S.size())
        {
            if (S.find(charJ, stone) != std::string::npos)
            {
                count++;
                stone = S.find(charJ, stone) + 1;
            }
            else
            {
                stone++;
            }
        }
    }
    return count;
}

// int main()
// {
//     std::cout << "Jewels and Stons" << std::endl;
//     std::cout << numJewelsInStones("aA", "aAAbbbb") << std::endl; // 3
//     std::cout << numJewelsInStones("z", "ZZ") << std::endl; // 0
//     std::cout << numJewelsInStones("abC", "BBBBaBBcccbbaA") << std::endl;
// }