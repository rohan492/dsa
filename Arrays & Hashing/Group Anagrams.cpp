class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& st : strs) {
            string tempSt = st;
            sort(begin(tempSt), end(tempSt));
            mp[tempSt].push_back(st);
        }
        vector<vector<string>> result;
        for (auto& it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};