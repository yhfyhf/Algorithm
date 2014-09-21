/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> temp;
        vector<int> res;
        if (!root)
            return res;
        temp.push(root);
        while (!temp.empty()) {
            TreeNode *node = temp.top();
            temp.pop();
            res.push_back(node->val);
            if (node->right)
                temp.push(node->right);
            if (node->left)
                temp.push(node->left);
        }
        return res;
    }
};