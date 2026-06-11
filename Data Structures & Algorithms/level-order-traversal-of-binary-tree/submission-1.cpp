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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> levelOrderT;
        if (root == nullptr) return levelOrderT;

        queue <TreeNode*> buffer; 
        buffer.push(root);

        while (!buffer.empty()) {
            vector<int> level;
            int size = buffer.size();

            while (size--) {
                TreeNode* current = buffer.front(); 
                buffer.pop();
                level.push_back(current->val);
                if (current->left) buffer.push(current->left);
                if (current->right) buffer.push(current->right);
            }

            levelOrderT.push_back(level);
        }

        return levelOrderT;
    }
};
