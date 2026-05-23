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
    bool isBalanced(TreeNode* root) 
    {
        bool valid = true;
        dfs(root, valid);
        return valid;
    }

    int dfs(TreeNode* root, bool& valid) 
    {
        if (root == nullptr || !valid)
            return 0;

        int left = dfs(root->left, valid);
        int right = dfs(root->right, valid);

        if (std::abs(left - right) > 1)
            valid = false;

        return 1 + std::max(left, right);
    }
};
