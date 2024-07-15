class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for (int i = 0; i <= n; i++) {
            ans[i] = hammingWeight(i);
        }        
        return ans;
    }
};