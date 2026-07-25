#include <util/timer.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if (head == nullptr)
            return nullptr;

        std::vector<Node*> nodes;
        std::unordered_map<Node*, Node*> mapping;

        Node* current = head;

        while (current != nullptr)
        {
            Node* newNode = new Node(current->val);
            nodes.push_back(newNode);
            mapping[current] = newNode;
            current = current->next;
        }

        Node* currentOld = head;
        current = nodes[0];

        for (int i = 1; i < nodes.size(); ++i)
        {
            current->next = nodes[i];
            current->random = currentOld->random ? mapping[currentOld->random] : nullptr;
            current = current->next;
            currentOld = currentOld->next;
        }
        current->random = currentOld->random ? mapping[currentOld->random] : nullptr;

        return nodes[0];
    }
};
