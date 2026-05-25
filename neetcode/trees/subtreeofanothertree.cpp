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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (matchesSubtree(root, subRoot))
            return true;
        else if (root == nullptr || subRoot == nullptr)
            return false;
        else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool matchesSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if ((root == nullptr) != (subRoot == nullptr))
            return false;
        if (root == nullptr)
            return true;
        
        return root->val == subRoot->val && matchesSubtree(root->left, subRoot->left) && matchesSubtree(root->right, subRoot->right);
    }
};