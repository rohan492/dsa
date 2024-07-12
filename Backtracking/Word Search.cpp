class Solution {
public:
    int m, n, l;
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool backtrack (vector<vector<char>>& board, string word, int i, int j, int idx) {
        if (idx == l) return true;
        if (i == -1 || i == m || j == -1 || j == n || board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (backtrack(board, word, new_i, new_j, idx + 1)) {
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }
    bool exist (vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.size();
        if (m*n < l) return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j] && backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};