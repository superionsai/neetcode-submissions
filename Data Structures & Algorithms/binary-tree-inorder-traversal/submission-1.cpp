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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> answer;
        stack <TreeNode*> buffer;
        TreeNode* current = root;
        while (!buffer.empty() || current != nullptr) {
            while (current != nullptr) {
                buffer.push(current);
                current = current->left;
            }
            current = buffer.top();
            buffer.pop();
            answer.push_back(current->val);
            current = current->right;
        }
        return answer;
    }
};