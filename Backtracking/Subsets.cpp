class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int index, vector<int>& curr) {
        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        backtrack(nums, index + 1, curr);

        curr.pop_back();
        backtrack(nums, index + 1, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums, 0, curr);
        return ans;
    }
};