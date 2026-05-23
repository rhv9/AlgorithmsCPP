#include <iostream>
#include <vector>
#include <stdint.h>
#include <stack>
#include <string>

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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int result = 0;
        dfs(root, result);

        return result;
    }

    int dfs(TreeNode* root, int& result)
    {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);

        result = std::max(result, left + right);
        return std::max(left, right) + 1;
    }
};