class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> arr(begin(mp), end(mp));
        auto comp = [&arr](pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        };
        sort(begin(arr), end(arr), comp);

        vector<int> result;
        for (auto& it : arr) {
            if (k == 0) {
                break;
            }
            result.push_back(it.first);
            k--;
        }
        return result;
    }
};