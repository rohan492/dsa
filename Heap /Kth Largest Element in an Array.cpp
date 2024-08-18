class Solution {
private:
    int quickSelect(vector<int>& nums, int l, int r) {
        int pivot = nums[l];
        int i = l + 1;
        int j = r;
        while(i <= j) {
            if (nums[i] < pivot && nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= pivot) i++;
            if (nums[j] <= pivot) j--;
        }
        swap(nums[j], nums[l]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int p_pos = 0;
        while(true) {
            p_pos = quickSelect(nums, l, r);
            if (p_pos == k - 1) {
                break;
            } else if (p_pos < k - 1) {
                l = p_pos + 1;
            } else {
                r = p_pos - 1;
            }
        }
        return nums[p_pos];
    }
};