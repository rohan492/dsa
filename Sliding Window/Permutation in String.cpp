class Solution {
private:
    bool isPermutation(vector<int>& count) {
        for (int i = 0; i < 26; i++)
            if (count[i] != 0) return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        vector<int> count(26);
        for (int i = 0; i < m; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = m; i < n; i++) {
            if (isPermutation(count)) return true;
            count[s2[i] - 'a']--;     // Take   i
            count[s2[i - m] - 'a']++; // Remove i - m
        }
        return isPermutation(count);
    }
};