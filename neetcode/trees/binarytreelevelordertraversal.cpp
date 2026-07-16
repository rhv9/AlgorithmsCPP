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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == nullptr)
            return {};

        std::queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        std::vector<std::vector<int>> results;

        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();
            std::vector<int> line;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* current = nodeQueue.front();
                nodeQueue.pop();

                line.push_back(current->val);

                if (current->left)
                    nodeQueue.push(current->left);
                if (current->right)
                    nodeQueue.push(current->right);
            }

            results.push_back(line);
        }

        return results;
    }
};
