class Solution {
public:
    void dfs(TreeNode* root, int maxSoFar, int& result) {
        if (!root) return;
        if (root->val >= maxSoFar) result++;
        dfs(root->left, max(maxSoFar, root->val), result);
        dfs(root->right, max(maxSoFar, root->val), result);
    }
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, root->val, result);
        return result;
    }
};