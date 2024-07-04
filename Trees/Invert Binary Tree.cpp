class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        root->left = right;
        root->right = left;
        return root;
    }
};