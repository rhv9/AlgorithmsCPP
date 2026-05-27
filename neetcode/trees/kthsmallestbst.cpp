#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>
#include <queue>

#include <util/timer.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int counter = 0;
        int result = kthSmallestInternal(root, k, counter);
        return result;
    }

    int kthSmallestInternal(TreeNode* root, int k, int& counter)
    {
        if (root == nullptr || counter > k)
            return -1;

        int left = kthSmallestInternal(root->left, k, counter);
        if (left != -1)
            return left;

        if (++counter == k)
            return root->val;

        int right = kthSmallestInternal(root->right, k, counter);

        if (right != -1)
            return right;

        return -1;
    }
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        std::stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        
        int counter = 0;
        TreeNode* cur = root;
        while (cur != nullptr || !nodeStack.empty())
        {
            while (cur != nullptr)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }
            cur = nodeStack.top();
            nodeStack.pop();

            ++counter;
            if (counter == k)
                return cur->val;
            
            cur = cur->right;
        }
        return -1;
    }
};
