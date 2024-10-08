class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}
    void set (string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }
        string res = "";
        int l = 0, r = mp[key].size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (mp[key][mid].first <= timestamp) {
                res = mp[key][mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};