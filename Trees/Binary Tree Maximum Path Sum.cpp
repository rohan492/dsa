class Solution {
public:
    int maxSum;
    int solve(TreeNode* root) {
        if (!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int subroot_max = l + r + root->val;
        int either_max = max(l, r) + root->val;

        maxSum = max({maxSum, root->val, subroot_max, either_max});
        return max({either_max, root->val});
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};