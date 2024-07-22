class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i == m || j == n || i == -1 | j == -1 || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '$';
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            dfs(grid, new_i, new_j);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};