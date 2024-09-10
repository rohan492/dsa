class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char& ch : t) {
            mp[ch]++;
        }
        int i = 0, j = 0;
        int minStart = 0, minLength = INT_MAX;
        int counter = t.size();
        while (j < s.size()) {
            if (mp[s[j]] > 0) {
                counter--;
            }
            mp[s[j]]--;
            j++;
            while (counter == 0) {
                if (j - i < minLength) {
                    minLength = j - i;
                    minStart = i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    counter++;
                }
                i++;
            }
        }
        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
    }
};