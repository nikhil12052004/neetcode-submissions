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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode;
        root->val = preorder[idx];
        int i;
        for(i = start; i<inorder.size(); i++){
            if(inorder[i] == root->val) break;
        }
        idx++;
        root->left = helper(preorder, inorder, start, i-1, idx);
        root->right = helper(preorder, inorder, i+1, end, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return helper(preorder, inorder, 0, n-1, idx);
    }
};
