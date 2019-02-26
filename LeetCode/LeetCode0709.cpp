//
//  LeetCode0709.cpp
//  
//
//  Created by Nuri Ra on 20.02.19.
//

#include <stdio.h>

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for To Lower Case.
// Memory Usage: 8.2 MB, less than 59.17% of C++ online submissions for To Lower Case.

class Solution {
public:
    string toLowerCase(string str) {
        
        char *cstr = new char[str.length()+1];
        
        strcpy(cstr, str.c_str());
        
        for(int i = 0 ; i < str.length() ; i++)
        {
            if(cstr[i] > 64 && cstr[i] < 91)
                cstr[i] += 32;
        }
        
        str = cstr;
        
        delete[] cstr;
        
        return str;
    }
};
