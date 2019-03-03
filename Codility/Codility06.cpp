//
//  Codility06.cpp
//  
//
//  Created by Nuri Ra on 12.02.19.
//

#include <stdio.h>

// Distinct
// 91%, Detected time complexity O(N*log(N)) or O(N)
// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int iLen = A.size();
    int i, cnt = 0;
    
    std::sort (A.begin(), A.end());
    
    for(i = 0; i < iLen ; i++)
    {
        if(A[i] != A[i+1])
            cnt++;
    }
    
    return cnt;
}

// 100%
// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int iLen = A.size();
    int i, cnt = 0;
    
    std::sort (A.begin(), A.end());
    
    if(iLen == 1)
        return 1;
    
    for(i = 0; i < iLen ; i++)
    {
        if(A[i] != A[i+1])
            cnt++;
    }
    
    return cnt;
}
