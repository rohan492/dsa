class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, result = 0;
        int n = nums.size();
        while(i < n - 1) {
            if (i + nums[i] >= n - 1) {
                result++;
                break;
            }
            int maxValue = 0;
            int maxIndex = i + 1;
            for (int j = i+1; j < i+1+nums[i]; j++) {
                if (j + nums[j] > maxValue) {
                    maxValue = j + nums[j];
                    maxIndex = j;
                }
            }
            i = maxIndex;
            result++;
        }
        return result;
    }
};