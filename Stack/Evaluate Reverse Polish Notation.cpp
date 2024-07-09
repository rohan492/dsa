class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<int (int, int)>> mp = {
            { "+", [](int a, int b) { return a + b; } },
            { "-", [](int a, int b) { return a - b; } },
            { "*", [](int a, int b) { return a * b; } },
            { "/", [](int a, int b) { return a / b; } }
        };
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                int result = mp[token](first, second);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};