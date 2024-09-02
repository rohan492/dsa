class Solution {
private:
    int solve(vector<int>& nums, int currIdx, int start, vector<int>& t) {
        if (currIdx < start) return 0;
        if (currIdx == start) return nums[start];
        if (t[currIdx] != -1) return t[currIdx];
        int rob_i = nums[currIdx] + solve(nums, currIdx-2, start, t);
        int not_rob_i = solve(nums, currIdx-1, start, t);
        return t[currIdx] = max(rob_i, not_rob_i);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> t1(n, -1);
        int withoutFirst = solve(nums, n-1, 1, t1);
        vector<int> t2(n, -1);
        int withoutLast = solve(nums, n-2, 0, t2);
        return max(withoutFirst, withoutLast);
    }
};