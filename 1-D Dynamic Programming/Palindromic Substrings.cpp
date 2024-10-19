// Top-Down
class Solution {
public:
    int t[1001][1001];
    bool check(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        if (s[i] == s[j]) {
            return t[i][j] = check(s, i+1, j-1);
        }
        return t[i][j] = false;
    }
    int countSubstrings(string s) {
        memset(t, -1, sizeof(t));
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Bottom-Up
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<bool>> t(n, vector<bool>(n, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i+L-1 < n; i++) {
                int j = i + L - 1;
                if (i == j) {
                    t[i][i] = true;
                } else if (i+1 == j) {
                    t[i][j] = (s[i] == s[j]);
                } else {
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }
                if (t[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};