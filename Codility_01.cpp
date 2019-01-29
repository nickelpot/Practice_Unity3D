//
//  main.cpp
//  Codility_1
//
//  Created by Nuri Ra on 30.11.18.
//  Copyright © 2018 Nuri Ra. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <stdio.h>
#include <string.h>

using namespace std;

// First Solution 80%
int solution1(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int iLength, i1Count, iGapCount = 0;
    int iGapA, iGapB = 0;
    int i, j; // for for roop
    string strValue;
    
    std::bitset<32> binValue(N);
    strValue = binValue.to_string();
    
    iLength = strValue.length();
    char charValue[iLength+1];
    
    strncpy(charValue, strValue.c_str(), sizeof(charValue));
    
    for(i = 0; i < iLength; i++)
        if(charValue[i] == '1')
            i1Count += 1;
    
    cout << binValue << "\n" << strValue << "\n" << charValue << "\n";
    cout << "i1Count : " << i1Count << "\n";
    
    if(i1Count > 1)
    {
        iGapCount = i1Count-1;
        j = 0;
        
        cout << "iGapCount : " << iGapCount << "\n";
        
        while(iGapCount > 0)
        {
            for(i = j; i < iLength; i++)
            {
                if(charValue[i] == '1')
                {
                    j = i+1;
                    iGapA = 0;
                    while(charValue[j] == '0')
                    {
                        iGapA += 1;
                        j += 1;
                    }
                    iGapB = (iGapA > iGapB) ? iGapA : iGapB;
                    
                    
                }
            }
            iGapCount -= 1;
        }
        
        return iGapB;
    }
    else
        return 0;
}

// Someone's Solution 1
int binaryGap(int n)
{
    const int size = sizeof(n) * 8;
    int mask = 1;
    int lastOneIndex = -1;
    int maxGap = 0;
    
    for (int i=0; i < size; i++)
    {
        if (mask > n)
            return maxGap;
        if ((n & mask) > 0)
        {
            if (lastOneIndex == -1)
            {
                lastOneIndex = i;
            }
            else
            {
                int gap = (i - lastOneIndex) - 1;
                if (gap > maxGap)
                {
                    maxGap = gap;
                }
                lastOneIndex = i;
            }
        }
        mask <<= 1;
    }
    return maxGap;
}

// Second Solution 100%
int solution2(int N) {
    // write your code in C++14 (g++ 6.2.0)
    
    int iMaxGap = 0, iGap = 0;
    int iTemp = 0, iFlag = 0;
    
    while (N > 1)
    {
        iTemp = N % 2;
        
        if (iTemp == 1)
        {
            iFlag++;
            iGap = 0;
        }
        else if (iFlag >= 1 && iTemp == 0)
        {
            iGap++;
            
            if (iGap > iMaxGap)
                iMaxGap = iGap;
        }
        
        N = N / 2;
    }
    
    return iMaxGap;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int temp = binaryGap(1041);
    
    std::cout << temp << "\n";
    std::cout << "Hello, World!\n";
    return 0;
}

