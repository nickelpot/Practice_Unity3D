//
//  Codility02.cpp
//  
//
//  Created by Nuri Ra on 17.01.19.
//
// OddOccurrencesInArray
// 22%
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int i, j, iCnt, iCal;
    int iLen = sizeof(A)/sizeof(A[0]);
    
    for(i=0; i<iLen+1; i++)
    {
        iCnt = 1;
        
        for(j=0; j<iLen+1; j++)
        {
            if(i != j && A[i] == A[j])
                iCnt++;
        }
        
        if(iCnt % 2 == 1)
            return A[i];
    }
}

// 100%

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int iLen = A.size();
    int i = 0, cnt = 1, result = 0;
    
    if(iLen == 1)
        return A[0];
    
    std::sort(A.begin(), A.end());
    
    for(i = 0; i < iLen ; i++)
    {
        if(i+1 == iLen)
            return A[i];
        
        if(A[i] == A[i+1])
            cnt++;
        else if(A[i] != A[i+1])
        {
            if(cnt%2 == 1)
                return A[i];
            else
                cnt = 1;
        }
    }
}


// Other's XOR solution (Python)
/*
 def solution(A):
 result = 0
 for number in A:
 result ^= number
 return result
 */
