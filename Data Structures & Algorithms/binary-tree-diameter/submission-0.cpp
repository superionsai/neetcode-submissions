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
    unordered_map <TreeNode*, int> depthMap;
    int _maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        if (depthMap.find(root->left) == depthMap.end())
            depthMap[root->left] = _maxDepth(root->left);
        if (depthMap.find(root->right) == depthMap.end())
            depthMap[root->right] = _maxDepth(root->right);

        depthMap[root] = max(1 + depthMap[root->left], 1 + depthMap[root->right]);
        return depthMap[root];
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int maxDia = _maxDepth(root->left) + _maxDepth(root->right);
        maxDia = max(maxDia, diameterOfBinaryTree(root->left));
        maxDia = max(maxDia, diameterOfBinaryTree(root->right));
        return maxDia;
    }
};
