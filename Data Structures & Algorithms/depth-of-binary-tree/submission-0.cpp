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
    int _maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth = max(1 + _maxDepth(root->right), 1 + _maxDepth(root->left));
        return depth;
    }
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        return _maxDepth(root);
    }
};
