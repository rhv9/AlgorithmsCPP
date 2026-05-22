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

// Recursive DFS
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// BFS
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;

        int level = 0;
        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();

            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                
                if (node->left != nullptr)
                    nodeQueue.push(node->left);
                if (node->right != nullptr)
                    nodeQueue.push(node->right);
            }
            ++level;
        }

        return level;
    }
};

