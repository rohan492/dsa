class Solution {
public:
    int n;
    vector<int> getNSL(vector<int>& heights) {
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> getNSR(vector<int>& heights) {
        stack<int> st;
        vector<int> res(n, n);
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        n = heights.size();
        vector<int> nsl = getNSL(heights);
        vector<int> nsr = getNSR(heights);
        for (int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = width * heights[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};