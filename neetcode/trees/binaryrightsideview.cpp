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
    vector<int> rightSideView(TreeNode* root) 
    {
        if (root == nullptr)
            return {};

        std::vector<int> results;

        struct TreeNodeLevel
        {
            TreeNode* node;
            int depth;
        };

        std::queue<TreeNodeLevel> nodeQueue;
        nodeQueue.push({root, 0});

        while (!nodeQueue.empty())
        {
            TreeNodeLevel treeNodeLevel = nodeQueue.front();
            nodeQueue.pop();

            if (treeNodeLevel.depth >= results.size())
                results.push_back(treeNodeLevel.node->val);
            else
                results[treeNodeLevel.depth] = treeNodeLevel.node->val;

            if (treeNodeLevel.node->left != nullptr)
                nodeQueue.push({treeNodeLevel.node->left, treeNodeLevel.depth + 1});

            if (treeNodeLevel.node->right != nullptr)
                nodeQueue.push({treeNodeLevel.node->right, treeNodeLevel.depth + 1});
        }

        return results;
    }   
};
