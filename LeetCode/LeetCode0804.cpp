//
//  main.cpp
//  LeetCode0804
//
//  Created by Nuri Ra on 22.02.19.
//  Copyright © 2019 Nuri Ra. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Unique Morse Code Words.
//Memory Usage: 9.6 MB, less than 22.35% of C++ online submissions for Unique Morse Code Words.

int uniqueMorseRepresentations(std::vector<std::string>& words) {
    int i, j;
    
    std::vector<std::string> alphabet = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    
    for(i = 0 ; i < words.size() ; i++)
    {
        std::string tmp;
        
        char* cstr = new char[words[i].size()+1];
        strcpy(cstr, words[i].c_str());

        for(j = 0 ; j < words[i].size() ; j++)
            tmp.append(alphabet[cstr[j]-97]);
        
        words[i] = tmp;
        
        delete[] cstr;
    }
    
    sort(words.begin(), words.end());
    auto remain = unique(words.begin(), words.end());
    words.erase(remain, words.end());

    return (int)words.size();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // std::cout << "Hello, World!\n";
    
    std::vector<std::string> words = {"gin", "zen", "gig", "msg"};
    
    int i = uniqueMorseRepresentations(words);
    
    std::cout << i;
    
    return 0;
}
