class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& rootIdx, unordered_map<int, int>& mp, int low, int high) {
        if (low > high) return NULL;
        TreeNode* node = new TreeNode(preorder[rootIdx]);
        int pivot = mp[preorder[rootIdx]];
        rootIdx++;
        node->left = solve(preorder, inorder, rootIdx, mp, low, pivot-1);
        node->right = solve(preorder, inorder, rootIdx, mp, pivot+1, high);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, rootIdx, mp, 0, inorder.size()-1);
    }
};