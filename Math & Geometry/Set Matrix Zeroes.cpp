class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFRowZero = false;
        bool isFColZero = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                isFColZero = true;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                isFRowZero = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (isFColZero) {
                matrix[i][0] = 0;
            } 
        }

        for (int i = 0; i < n; i++) {
            if (isFRowZero) {
                matrix[0][i] = 0;
            } 
        }
    }
};