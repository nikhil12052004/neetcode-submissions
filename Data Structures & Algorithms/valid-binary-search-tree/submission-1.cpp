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
    bool valid(TreeNode* node, long long left, long long right) {
        if(node == NULL)
            return true;

        if(!(node->val < right && node->val > left))
            return false;

        return valid(node->left, left, node->val) &&
               valid(node->right, node->val, right);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, INT_MIN, INT_MAX);
    }
};
