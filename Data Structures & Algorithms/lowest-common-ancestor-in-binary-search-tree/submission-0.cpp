/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    bool isChild(TreeNode* root, TreeNode* child) {
        if (root == child || child == nullptr) return true;
        if (root == nullptr) return false;
        return (isChild(root->left, child) || isChild(root->right, child));
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) return root;
        if (p == nullptr) return q;
        if (q == nullptr) return p;

        TreeNode* current = root;
        while (true) {
            if (isChild(current->left, p) && isChild(current->left, q)) current = current->left;
            else if (isChild(current->right, p) && isChild(current->right, q)) current = current->right;
            else return current;
        }

        return current;
    }
};
