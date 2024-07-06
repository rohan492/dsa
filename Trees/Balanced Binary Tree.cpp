class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};