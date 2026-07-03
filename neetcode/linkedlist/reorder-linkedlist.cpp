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
    void reorderList(ListNode* head) 
    {
        std::vector<ListNode*> nodes;

        ListNode* current = head;
        
        while (current != nullptr)
        {
            nodes.push_back(current);
            current = current->next;    
        }
        current = head;
        for (int i = 0; i < nodes.size() / 2; ++i)
        {
            int pos = nodes.size() - 1 - i;
            ListNode* temp = current->next;
            current->next = nodes[pos];
            current->next->next = temp;
            current = temp;
        }
        
        nodes[nodes.size() / 2]->next = nullptr;
    }
};
