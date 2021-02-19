#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>

int calculateNumber (int n)
{
    std::string strN = std::to_string(n);
    int result = 0;
    for(int i = 0 ; i < strN.size() ; i++)
    {
        int num = strN.at(i) - '0';
        if (num != 0)
        {
            result += pow(num, 2);
        }
    }
    return result;
}

bool isHappy(int n) {
    while(n != 1)
        {
            int num = calculateNumber(n);
            if (pow(n, 2) == num)
            {
                return false;
            }
            n = num;
        }
        return true;
}

/*int main()
{
    std::cout << "HappyNumber: " << isHappy(1111111) << std::endl;
}*/