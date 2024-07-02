class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for (string& st : strs) {
            res += to_string(st.size()) + '#' + st;
        }
        return res;
    }
    vector<string> decode(string& strs) {
        int i = 0;
        int n = strs.size();
        vector<string> res;
        while (i < n) {
            int posOfHash = n;
            for (int start = i; start < n; start++) {
                if (strs[start] == '#') {
                    posOfHash = start;
                    break;
                }
            }
            int len = stoi(strs.substr(i, posOfHash - i));
            i = posOfHash + 1;
            res.push_back(strs.substr(i, len));
            i += len;
        }
        return res;
    }
};