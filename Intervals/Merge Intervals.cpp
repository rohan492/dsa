class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int i = 0;
        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } else {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start, end});
        return result;
    }
};