class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSize = 0;
        int i = 0, j = 0;
        unordered_set<int> st;
        while (j < s.size()) {
            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }
            maxSize = max(maxSize, j - i + 1);
            st.insert(s[j]);
            j++;
        }
        return maxSize;
    }
};