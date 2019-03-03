//
//  LeetCode0557.cpp
//  
//
//  Created by Nuri Ra on 27.02.19.
//
// Runtime: 36 ms, faster than 17.94% of C++ online submissions for Reverse Words in a String III.
// Memory Usage: 13.8 MB, less than 28.91% of C++ online submissions for Reverse Words in a String III.

#include <stdio.h>

class Solution {
public:
    string reverseWords(string s) {
        string result;
        
        char * cstr = new char [s.length()+1];
        strcpy (cstr, s.c_str());
        
        char * word = strtok (cstr," ");
        
        while (word != NULL)
        {
            for(int i = strlen(word)-1 ; i >= 0 ; i--)
                result.push_back(word[i]);
            
            word = strtok(NULL," ");
            
            if(word != NULL)
                result.push_back(' ');
        }
        
        delete[] cstr;
        
        return result;
    }
};
