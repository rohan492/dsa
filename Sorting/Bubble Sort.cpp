#include <vector>
using namespace std;

class Solution {
public:
    void bubble_sort(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            bool isSwapped = false;
            for (int j = 0; j < n-1; j++) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    isSwapped = true;
                }
            }
            if (!isSwapped) {
                break;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        bubble_sort(nums, n);
        return nums;
    }
};