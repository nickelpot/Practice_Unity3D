//
//  Codility07.cpp
//  
//
//  Created by Nuri Ra on 03.03.19.
//

#include <stdio.h>

// Brackets
// 25%
int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    
    if(*S.begin() == 91)
    {
        if(*(S.end()-1) == 93)
            return 1;
    }
    else if(*S.begin() == 123)
    {
        if(*(S.end()-1) == 125)
            return 1;
    }
    else if(*S.begin() == (*(S.end()-1))-1)
        return 1;
    else
        return 0;
}

// 50%
// you can use includes, for example:
#include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> stk;
    
    if(S.size() < 2)
        return 1;
    
    for(int i = S.size()-1 ; i >= 0 ; i--)
        stk.push(S.at(i));
    
    if(stk.top() == '(')
    {
        stk.pop();
        
        while(!stk.empty())
        {
            if(stk.top() == ')')
            {
                stk.pop();
                if(stk.empty()) return 1;
                else return 0;
            }
            
            stk.pop();
        }
    }
    else if(stk.top() == '[')
    {
        stk.pop();
        
        while(!stk.empty())
        {
            if(stk.top() == ']')
            {
                stk.pop();
                if(stk.empty()) return 1;
                else return 0;
            }
            
            stk.pop();
        }
    }
    else if(stk.top() == '{')
    {
        stk.pop();
        
        while(!stk.empty())
        {
            if(stk.top() == '}')
            {
                stk.pop();
                if(stk.empty()) return 1;
                else return 0;
            }
            
            stk.pop();
        }
    }
    
    return 0;
}

// 75%
// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> check;
    
    if(S.size() % 2)
        return 0;
    if(S.empty())
        return 1;
    
    for(int i = 0 ; i < S.size() ; i++)
    {
        if(S.at(i) == '(' || S.at(i) == '[' || S.at(i) == '{')
            check.push(S.at(i));
        else
        {
            if(check.empty())
                return 0;
            
            if(S.at(i) == ')' && check.top() != '(')
                return 0;
            else if(S.at(i) == ']' && check.top() != '[')
                return 0;
            else if(S.at(i) == '}' && check.top() != '{')
                return 0;
            
            check.pop();
        }
    }
    
    return 1;
}

// 100% Detected time complexity: O(N)
// you can use includes, for example:
// #include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> check;
    
    if(S.size() % 2)
        return 0;
    if(S.empty())
        return 1;
    
    for(int i = 0 ; i < S.size() ; i++)
    {
        if(S.at(i) == '(' || S.at(i) == '[' || S.at(i) == '{')
            check.push(S.at(i));
        else
        {
            if(check.empty())
                return 0;
            
            if(S.at(i) == ')' && check.top() != '(')
                return 0;
            else if(S.at(i) == ']' && check.top() != '[')
                return 0;
            else if(S.at(i) == '}' && check.top() != '{')
                return 0;
            
            check.pop();
        }
    }
    
    if(!check.empty())
        return 0;
    
    return 1;
}
