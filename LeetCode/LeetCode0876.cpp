//
//  LeetCode0876.cpp
//  
//
//  Created by Nuri Ra on 26.02.19.
//

#include <stdio.h>

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
// Memory Usage: 8.6 MB, less than 22.49% of C++ online submissions for Middle of the Linked List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        vector<ListNode*> result = {head};
        
        while(result.back()->next != NULL)
            result.push_back(result.back()->next);
        
        return result[result.size() / 2];
    }
};
