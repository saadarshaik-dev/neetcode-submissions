class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int n = heights.size();
        int mx = 0;

        for (int i = 0; i < n; i++) {
            int start = i;

                while (!s.empty() && s.top().second > heights[i]) {
                    int h = s.top().second;
                    int idx = s.top().first;
                    s.pop();
                    int area = h*(i-idx);
                    mx = max(mx, area);
                    start = idx;
                }
            s.push({start,heights[i]});
        }
        while (!s.empty()) {
            auto [idx, h] = s.top();
            s.pop();
            mx = max(mx, h * (n - idx));
        }
        return mx;
    }
};
