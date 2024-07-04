class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int longestSeq = 0;
        for (int& num : nums) {
            if (st.find(num - 1) == st.end()) {
                int currentSeq = 1;
                while(st.find(++num) != st.end()) {
                    currentSeq += 1;
                }
                longestSeq = max(longestSeq, currentSeq);
            }
        }
        return longestSeq;
    }
};