class Solution {
public:
    bool solve(TreeNode* root, long low, long high) {
        if (!root) {
            return true;
        }
        if (root->val > low && root->val < high) {
            return solve(root->left, low, root->val) && solve(root->right, root->val, high);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return solve(root, LONG_MIN, LONG_MAX);
    }
};