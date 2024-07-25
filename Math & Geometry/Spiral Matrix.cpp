class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;

        vector<int> result;
        while(left <= right && top <= bottom) {
            // store elements from top row
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // store elements from right column
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                // store elements from bottom row
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
            }
            bottom--;

            if (left <= right) {
                // store elements from left column
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
        }

        return result;
    }
};