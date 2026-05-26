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

struct ParentNode
{
    TreeNode* node;
    bool isLeft;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        std::vector<ParentNode> currentPath;
        return isValidBSTInternal(currentPath, root);
    }

    bool isValidBSTInternal(std::vector<ParentNode>& currentPath, TreeNode* root)
    {
        if (root == nullptr)
            return true;

        bool validParents = true;
        for (ParentNode& parentNode : currentPath)
        {
            if (parentNode.node->val == root->val || 
                parentNode.isLeft && root->val > parentNode.node->val ||
                !parentNode.isLeft && root->val < parentNode.node->val)
                return false;
        }

        // left
        if (root->left != nullptr)
        {
            currentPath.push_back({root, true});
            bool valid = isValidBSTInternal(currentPath, root->left);
            currentPath.pop_back();
            if (!valid)
                return false;
        }
        if (root->right != nullptr)
        {
            currentPath.push_back({root, false});
            bool valid = isValidBSTInternal(currentPath, root->right);
            currentPath.pop_back();
            if (!valid)
                return false;
        }
        return true;
    }
    
};

// CANT BELIEVE I DIDN'T THINK OF THIS SOLUTION
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return isValidBSTInternal(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTInternal(TreeNode* root, int left, int right)
    {
        return root == nullptr || 
        root->val > left && root->val < right 
        && isValidBSTInternal(root->left, left, root->val) 
        && isValidBSTInternal(root->right, root->val, right);
    }
};