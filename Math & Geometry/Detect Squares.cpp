class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> mp; // x -> (y -> count)
    DetectSquares() {}

    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int res = 0;
        for (auto& it : mp) {
            int x3 = it.first;
            for (auto& it2 : it.second) {
                int y3 = it2.first;
                if (abs(x3 - x1) == 0 || abs(x3 - x1) != abs(y3 - y1)) {
                    continue;
                }
                res += mp[x3][y3] * mp[x1][y3] * mp[x3][y1];
            }
        }
        return res;
    }
};