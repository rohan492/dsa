class Solution {
public:
    vector<vector<string>> result;
    unordered_set<int> column;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;
    void backtrack(vector<string>& board, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (
                  column.find(col) != column.end() ||
                  diag.find(row + col) != diag.end() ||
                  antiDiag.find(row - col) != antiDiag.end()
               )
                continue;

            board[row][col] = 'Q';
            column.insert(col);
            diag.insert(row + col);
            antiDiag.insert(row - col);

            backtrack(board, row + 1, n);

            board[row][col] = '.';
            column.erase(col);
            diag.erase(row + col);
            antiDiag.erase(row - col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, n);
        return result;
    }
};