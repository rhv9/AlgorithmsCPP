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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == nullptr || p == nullptr || q == nullptr)
            return root;
        
        std::queue<TreeNode*> pPath, qPath;

        findNodePath(pPath, root, p);
        findNodePath(qPath, root, q);

        TreeNode* lca = root;
        while ((pPath.size() > 0 && qPath.size() > 0) && pPath.front() == qPath.front())
        {
            lca = pPath.front();
            pPath.pop();
            qPath.pop();
        }

        return lca;
    }

    void findNodePath(std::queue<TreeNode*>& path, TreeNode* root, TreeNode* findNode)
    {
        if (root == nullptr || findNode == nullptr)
            return;
        
        path.push(root);

        if (root->val == findNode->val)
            return;

        if (findNode->val < root->val)
            findNodePath(path, root->left, findNode);
        else
            findNodePath(path, root->right, findNode);

    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == nullptr || p == nullptr || q == nullptr)
            return root;

        if (root->val == p->val || root->val == q->val)
            return root;
            
        if (p->val < root->val != q->val < root->val)
            return root;
        else if (p->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};


class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* current = root;
        while (current != nullptr)
        {
            if      (p->val < root->val && q->val < root->val)
                current = current->left;
            else if (p->val > root->val && q->val > root->val)
                current = current->right;
            else
                return current;   
        }
        return current;
    }
};


int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->left = new TreeNode(5);


    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(3);
    TreeNode* q = new TreeNode(5);

    std::cout << Solution2().lowestCommonAncestor(root, p, q)->val << std::endl;

}