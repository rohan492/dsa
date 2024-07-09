class Solution {
public:
    vector<string> resultArr;
    void solve(string& result, int n, int open, int closed) {
        if (result.size() == 2*n) {
            resultArr.push_back(result);
            return;
        }

        if (open < n) {
            result.push_back('(');
            solve(result, n, open+1, closed);
            result.pop_back();
        }

        if (closed < open) {
            result.push_back(')');
            solve(result, n, open, closed+1);
            result.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string result = "";
        solve(result, n, 0, 0);
        return resultArr;
    }
};