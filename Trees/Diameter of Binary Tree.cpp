class Solution {
public:
    int maxDepth(TreeNode* root, int& result) {
        if (!root) return 0;
        int leftHeight = maxDepth(root->left, result);
        int rightHeight = maxDepth(root->right, result);
        result = max(result, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        maxDepth(root, result);
        return result;
    }
};