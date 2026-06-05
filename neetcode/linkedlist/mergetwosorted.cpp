#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>

#include <util/timer.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* head = new ListNode();
        ListNode* current = head;
        ListNode* left = list1;
        ListNode* right = list2;

        while (left && right)
        {
            if (left->val < right->val)
            {
                current->next = left;
                left = left->next;
            }
            else
            {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        if (left != nullptr)
            current->next = left;
        else if (right != nullptr)
            current->next = right;
            
        return head->next;
    }
};
