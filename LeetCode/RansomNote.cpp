#include <stdio.h>
#include <iostream>
#include <string>

bool canConstruct(std::string ransomNote, std::string magazine)
{
    int ransomContain = 0;

    if (ransomNote.size() == 0)
    {
        return true;
    }

    if (ransomNote.size() > magazine.size())
    {
        return false;
    }

    for (const char& ransomChar : ransomNote)
    {
        if (magazine.find(ransomChar) != std::string::npos)
        {
            magazine.erase(std::find(magazine.begin(), magazine.end(), ransomChar));
            ransomContain++;
        }
    }
    return ransomContain == ransomNote.size() ? true : false;
}

// int main()
// {
//     std::cout << "Ransom Note" << std::endl;
//     std::cout << canConstruct("a", "b") << std::endl; // false
//     std::cout << canConstruct("aa", "ab") << std::endl; // false
//     std::cout << canConstruct("aa", "aab") << std::endl; // true
//     std::cout << canConstruct("fffbfg", "effjfggbffjdgbjjhhdegh") << std::endl; // true
// }