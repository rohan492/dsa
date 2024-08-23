class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, res = 0, max_f = 0;
        vector<int> count(26);
        while (j < s.size()) {
            count[s[j] - 'A']++;
            max_f = max(max_f, count[s[j] - 'A']);
            if (j - i + 1 - max_f > k) {
                count[s[i] - 'A']--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};