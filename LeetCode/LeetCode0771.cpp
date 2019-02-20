//
//  LeetCode0771.cpp
//  
//
//  Created by Nuri Ra on 20.02.19.
//

// Runtime: 8 ms, faster than 99.42% of C++ online submissions for Jewels and Stones.
// Memory Usage: 9.7 MB, less than 83.39% of C++ online submissions for Jewels and Stones.
#include <stdio.h>

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int i, cnt=0;
        
        char *cstr = new char[J.length()+1];
        strcpy(cstr, J.c_str());
        
        for(i = 0; i < J.length()+1 ; i++)
        {
            cnt = cnt + count(S.begin(), S.end(), cstr[i]);
        }
        
        delete[] cstr;
        return cnt;
    }
};
