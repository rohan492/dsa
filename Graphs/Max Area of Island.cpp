class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i == m || j == n || i == -1 | j == -1 || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = -1;
        int area = 1;
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            area += dfs(grid, new_i, new_j);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};