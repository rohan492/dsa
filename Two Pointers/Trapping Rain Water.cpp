class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = heights[0];
        right[n-1] = heights[n-1];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], heights[i]);
            right[n-i-1] = max(right[n-i], heights[n-i-1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - heights[i];
        }
        return ans;
    }
};