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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL) return "#,";
        s += to_string(root->val) + ",";
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* helper(stringstream &s){
        string str;
        getline(s, str, ',');
        if(str == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(str));
        node->left = helper(s);
        node->right = helper(s);

        return node;
    }

    TreeNode* deserialize(string data) {
        stringstream s(data);
        return helper(s);    
    }
};
