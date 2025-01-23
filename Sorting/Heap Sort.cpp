#include <vector>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nums[largest] < nums[left]) {
            largest = left;
        }
        if (right < n && nums[largest] < nums[right]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }
    void build_heap(vector<int>& nums, int n) {
        for (int i = n/2 -1; i >= 0; i--) {
            heapify(nums, n, i);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        build_heap(nums, n);
        for (int i = n-1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};