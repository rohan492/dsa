// Top Down Approach
class Solution {
public:
    int t[1001][1001];

    bool solve(string& s, int i, int j) {
        if (i >= j) {
            return 1;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j]) {
            return t[i][j] = solve(s, i + 1, j - 1);
        }

        return t[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        memset(t, -1, sizeof(t));

        int maxLen = INT_MIN, sp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};

// Bottom-up Approach
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxL = 1;
        int sp = 0;
        vector<vector<bool>> t(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            t[i][i] = true;
        }
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n-L+1; i++) {
                int j = i + L - 1;
                if (s[i] == s[j] && L == 2) {
                    t[i][j] = true;
                    maxL = 2;
                    sp = i;
                } else if (s[i] == s[j] && t[i+1][j-1]) {
                    t[i][j] = true;
                    if (maxL < j-i+1) {
                        maxL = j - i + 1;
                        sp = i;
                    }
                } else {
                    t[i][j] = false;
                }
            }
        }
        return s.substr(sp, maxL);
    }
};