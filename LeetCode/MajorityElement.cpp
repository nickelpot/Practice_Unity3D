#include <stdio.h>
#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

// int main()
// {
//     std::vector<int> arr = {2,2,1,1,1,2,2};
//     std::cout << "Majority Element" << std::endl;
//     std::cout << majorityElement(arr) << std::endl; // 2
// }