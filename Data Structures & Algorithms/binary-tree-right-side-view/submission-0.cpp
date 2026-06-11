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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> level;
        if (root == nullptr) return level;

        queue <TreeNode*> buffer; 
        buffer.push(root); 
        TreeNode* current;

        while (!buffer.empty()) {
            int size = buffer.size();

            while (size--) {
                current = buffer.front(); 
                buffer.pop();
                if (current->left) buffer.push(current->left);
                if (current->right) buffer.push(current->right);
            }

            level.push_back(current->val);
        }
        return level;
    }
};
