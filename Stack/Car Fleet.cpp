class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> timeArr;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            int distance = target - position[i];
            double time = (double) distance / speed[i];
            timeArr.push_back({position[i], time});
        }
        sort(begin(timeArr), end(timeArr));
        int result = 0;
        double maxTime = 0.0;
        for (int i = n - 1; i >= 0; i--) {
            if (maxTime < timeArr[i].second) {
                maxTime = timeArr[i].second;
                result++;
            }
        }
        return result;
    }
};