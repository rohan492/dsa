#include <vector>
using namespace std;

class Solution {
public:
    void selection_sort(vector<int>& nums, int n) {
        for (int i = 0; i < n-1; i++) {
            int min_idx = i;
            for (int j = i+1; j < n; j++) {
                if (nums[j] < nums[min_idx]) {
                    min_idx = j;
                }
            }
            if (min_idx != i) {
                swap(nums[min_idx], nums[i]);
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        selection_sort(nums, n);
        return nums;
    }
};