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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* nthPointer = head;
        int counter = 0;
        ListNode* current = head;

        while (current != nullptr)
        {
            ++counter;
            if (counter > n+1)
                nthPointer = nthPointer->next;
            current = current->next;
        }

        if (nthPointer == head && counter == n)
            return head->next;

        nthPointer->next = nthPointer->next->next;
        return head;
    }
};
