//
//  main.cpp
//  Interview_1
//
//  Created by Nuri Ra on 18.06.18.
//  Copyright © 2018 Nuri Ra. All rights reserved.
//

#include <iostream>

int iTokenCnt = 0;

std::string* tokenSentence;

void makeToken(std::string strSentence)
{
    int i       = 0;
    int iLength  = strSentence.size();
    
    char charSentence[iLength];
    char *token;
    
    strcpy(charSentence, strSentence.c_str());
    
    // Delete special characters, count of all sentence
    for(i=0; i<iLength; i++)
    {
        if(64 < charSentence[i] && charSentence[i] < 91); // 'A' ~ 'Z'
        else if(96 < charSentence[i] && charSentence[i] < 123); // 'a' ~ 'z'
        else if(charSentence[i] == ' ') // ' '
            iTokenCnt++;
        else
            charSentence[i] = ' ';
    }
    iTokenCnt       = iTokenCnt+1;

    // Input of all sentence
    i = 0;
    tokenSentence = new std::string[iTokenCnt];

    token = strtok(charSentence, " ");
    
    while(token != NULL)
    {
        tokenSentence[i] = token;
        i++;
        
        token = strtok(NULL, " ");
    }
}

void countToken(std::string* tokenSentence)
{
    int iCount;
    int i, j;

    std::string strStandard;
    
    // Count of removal duplicated value
    for(i=0; i<iTokenCnt; i++)
    {
        if(tokenSentence[i] != "")
        {
            strStandard = tokenSentence[i];
            iCount = 0;
            
            for(j=0; j<iTokenCnt; j++)
            {
                if(strStandard == tokenSentence[j])
                {
                    tokenSentence[j] = "";
                    iCount++;
                }
            }
            std::cout << strStandard << " -> " << iCount << "\n";
        }
    }
}

// Second Solution
void countString(std::string strSnt)
{
    int i = 0;
    int iCnt[26] = {0, };
    
    unsigned long iLng  = strSnt.size();

    // Count
    for(i=0; i<iLng ; i++)
    {
        if(64 < strSnt[i] && strSnt[i] < 91) // 'A' ~ 'Z'
            iCnt[strSnt[i] - 65]++;
        else if(96 < strSnt[i] && strSnt[i] < 123) // 'a' ~ 'z'
            iCnt[strSnt[i] - 97]++;
    }
    
    // Print
    for(i=0; i<27; i++)
    {
        if(iCnt[i] > 0)
            std::cout << char(i+65) << " -> " << iCnt[i] << "\n";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // std::cout << "Hello, World!\n";
    
    std::string strSnt;
    
    std::cout << "Input : ";
    std::cin >> strSnt;
    
    countString(strSnt);
    
    //makeToken(strSentence);
    //countToken(tokenSentence);
    
    delete[] tokenSentence;
    
    return 0;
}
