//
//  LeetCode0509.cpp
//  
//
//  Created by Nuri Ra on 26.02.19.
//

#include <stdio.h>

// Runtime: 16 ms, faster than 32.44% of C++ online submissions for Fibonacci Number.
// Memory Usage: 8.6 MB, less than 23.37% of C++ online submissions for Fibonacci Number.

class Solution {
public:
    int fib(int N) {
        if (N == 0)
            return 0;
        else if (N == 1)
            return 1;
        else
            return fib(N-1) + fib(N-2);
    }
};
