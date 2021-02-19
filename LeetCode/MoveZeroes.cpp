#include <stdio.h>
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int zeroCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            nums.erase(nums.begin()+i);
            i--;
            zeroCount ++;
        }
    }
    while(zeroCount > 0)
    {
        nums.push_back(0);
        zeroCount--;
    }

    for(int& num : nums)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

void moveZeroesShort(std::vector<int>& nums) {
    int count = 0;
    for (int& num : nums)
    {
        if (num != 0)
        {
            nums[count++] = num;
        }
    }
    while(count < nums.size())
    {
        nums[count++] = 0;
    }

    std::cout << "Short ver: ";
    for(int& num : nums)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}
// int main()
// {
//     std::vector<int> nums = {0,0,1}; //{0,1,0,3,12};
//     std::cout << "Move Zeroes: ";
//     moveZeroes(nums);
//     moveZeroesShort(nums);
// }