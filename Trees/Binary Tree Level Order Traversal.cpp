class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultArr;
        if (!root) return resultArr;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> result;

            while(size--) {
                TreeNode* node = q.front();
                q.pop();

                result.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            resultArr.push_back(result);
        }

        return resultArr;
    }
};