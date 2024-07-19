class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> subsets;
    void backtrack(string& s, int idx, vector<string>& currSubset) {
        if (idx == s.size()) {
            subsets.push_back(currSubset);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                currSubset.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, i + 1, currSubset);
                currSubset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> currSubset;
        backtrack(s, 0, currSubset);
        return subsets;
    }
};