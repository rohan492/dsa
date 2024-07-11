class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& curr) {
        if (index == candidates.size() || target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], index, curr);
        curr.pop_back();
        backtrack(candidates, target, index + 1, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, target, 0, curr);
        return ans;
    }
};