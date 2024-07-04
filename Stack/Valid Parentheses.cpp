class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (char& ch : s) {
            if (st.empty() || ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if ((ch == ')' && st.top() != '(') ||
                    (ch == ']' && st.top() != '[') ||
                    (ch == '}' && st.top() != '{')) {
                        return false;
                    }
                st.pop();
            }
        }
        return st.empty();
    }
};