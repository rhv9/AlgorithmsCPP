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
    ListNode* reverseList(ListNode* head) 
    {
        if (head == nullptr)
            return nullptr;

        ListNode* ending = nullptr;
        ListNode* current = head;
        while (current != nullptr)
        {
            ListNode* temp = current->next;
            current->next = ending;
            ending = current;
            current = temp;
        }

        return ending;
    }
};

int main()
{
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    ListNode* test = Solution().reverseList(head);
    while (test != nullptr)
    {
        std::cout << test->val << std::endl;
        test = test->next;
    }
}
