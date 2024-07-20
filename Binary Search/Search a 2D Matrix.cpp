class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lr = 0, hr = m - 1;
        while(lr < hr) {
            int mid = lr + (hr-lr)/2;
            if(matrix[mid][0] == target) {
                return true;
            }
            if(matrix[mid][0] < target && target < matrix[mid+1][0]) {
                lr = mid;
                break;
            }
            if(matrix[mid][0] < target) {
                lr = mid + 1;
            } else {
                hr = mid - 1;
            }
        }
        int lc = 0, hc = n - 1;
        while(lc <= hc) {
            int mid = lc + (hc-lc)/2;
            if(matrix[lr][mid] == target) {
                return true;
            } else if(matrix[lr][mid] < target) {
                lc = mid + 1;
            } else {
                hc = mid - 1;
            }
        }
        return false;
    }
};