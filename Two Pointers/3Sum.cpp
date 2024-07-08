class Solution {
public:
    void twoSum(vector<int>& nums, int target, int start, vector<vector<int>>& result) {
        int n = nums.size();
        int l = start, r = n - 1;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                l++;
            } else if (nums[l] + nums[r] > target) {
                r--;
            } else {
                result.push_back({-target, nums[l], nums[r]});
                while (l < r && nums[l] == nums[l+1]) l++;
                while (l < r && nums[r] == nums[r-1]) r--;
                l++;
                r--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(begin(nums), end(nums));
        if (nums[0] > 0) return {};

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            twoSum(nums, -nums[i], i+1, result);
        }
        return result;
    }
};