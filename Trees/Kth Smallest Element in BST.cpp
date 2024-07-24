class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        stack<TreeNode*> st;
        while(curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            k--;
            curr = st.top();
            st.pop();
            if (k == 0) {
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
    }
};