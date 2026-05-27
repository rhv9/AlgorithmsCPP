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
    int goodNodes(TreeNode* root) 
    {
        return goodNodesInternal(root, root->val);
    }

    int goodNodesInternal(TreeNode* root, int largest)
    {
        if (root == nullptr)
            return 0;
        
        if (root->val >= largest)
            return 1 + goodNodesInternal(root->left, root->val) + goodNodesInternal(root->right, root->val);
        
        return goodNodesInternal(root->left, largest) + goodNodesInternal(root->right, largest);
    }
};
