class Solution {
public:
    unordered_map<char, string> mp = {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" },
    };
    vector<string> result;
    void solve(string digits, int index, string res) {
        if (index == digits.size()) {
            result.push_back(res);
            return;
        }
        string str = mp[digits[index]];
        for (int i = 0; i < str.size(); i++) {
            res.push_back(str[i]);
            solve(digits, index + 1, res);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        string res = "";
        solve(digits, 0, res);
        return result;
    }
};