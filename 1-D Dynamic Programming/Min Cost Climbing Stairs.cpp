class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0;
        }

        if (t[i] != -1) return t[i];

        return t[i] = cost[i] + min(solve(cost, i+1), solve(cost, i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));
        return min(solve(cost, 0), solve(cost, 1));
    }
};