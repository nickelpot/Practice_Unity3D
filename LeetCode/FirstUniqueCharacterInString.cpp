#include <stdio.h>
#include <iostream>
#include <string>

int firstUniqChar(std::string s)
{
    for (int i = 0; i < s.size() ; i++)
    {
        if (s.find(s[i]) == i && s.find(s[i], i+1) == std::string::npos)
        {
            return i;
        }
    }
    return -1;
}

// int main()
// {
//     std::cout << "First Unique Character in String" << std::endl;
//     std::cout << firstUniqChar("leetcode") << std::endl; // 0
//     std::cout << firstUniqChar("loveleetcode") << std::endl; // 2
//     std::cout << firstUniqChar("cc") << std::endl; // -1
//     std::cout << firstUniqChar("") << std::endl; // -1
//     std::cout << firstUniqChar("aadadaad") << std::endl; // -1
// }