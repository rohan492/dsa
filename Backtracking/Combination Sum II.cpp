class Solution {
public:
    void backtrack(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& res, int startIndex, int sumTillNow, int target) {
        if (sumTillNow > target) {
            return;
        }
        if (sumTillNow == target) {
            res.push_back(curr);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++) {
            if (i > startIndex && candidates[i] == candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates, curr, res, i+1, sumTillNow + candidates[i], target);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(candidates, curr, res, 0, 0, target);
        return res;
    }
};