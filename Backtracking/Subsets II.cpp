class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<int> curr;
        vector<vector<int>> res;
        backtrack(nums, 0, curr, res);
        return res;
    }
};