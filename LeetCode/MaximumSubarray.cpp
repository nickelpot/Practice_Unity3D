#include <stdio.h>
#include <iostream>
#include <vector>

int maxSubArray(std::vector<int>& nums) {
    int max_sum = 0, max_sum_result = INT_MIN;
    for (auto& num : nums)
    {
        max_sum += num;
        max_sum_result = max_sum > max_sum_result ? max_sum : max_sum_result;
        max_sum = max_sum > 0 ? max_sum : 0;
    }
    return max_sum_result;
}

int maxSubArraySum(std::vector<int>& nums) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < nums.size(); i++) 
    { 
        max_ending_here = max_ending_here + nums[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

/*int main()
{
    std::vector<int> nums = {-2, -1};
    std::cout << "Maximum Subarray: " << maxSubArray(nums) << std::endl;
    std::cout << maxSubArraySum(nums) << std::endl;
}*/