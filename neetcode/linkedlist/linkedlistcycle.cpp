#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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
    bool hasCycle(ListNode* head) 
    {
        std::unordered_set<ListNode*> found; 
        ListNode* current = head;
        while (current)
        {
            if (found.count(current) == 0)
            {
                found.insert(current);
                current = current->next;
            }
            else
                return true;
        }
        return false;
    }
};
