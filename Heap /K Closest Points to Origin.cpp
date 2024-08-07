class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> triples;
        for (vector<int>& p : points) {
            triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(begin(triples), end(triples));
        vector<vector<int>> res;
        while(k--) {
            vector<int> closest = pq.top();
            pq.pop();
            res.push_back({closest[1], closest[2]});
        }
        return res;
    }
};