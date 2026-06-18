class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> trackedTemps;
        vector<int> ans(temperatures.size(), 0);

        trackedTemps.push({temperatures[0], 0});

        for (int i = 1; i < temperatures.size(); i++) {
            while (!trackedTemps.empty() && temperatures[i] > trackedTemps.top().first) {
                auto [temp, idx] = trackedTemps.top();
                trackedTemps.pop();
                ans[idx] = i-idx;
            }
            trackedTemps.push({temperatures[i], i});
        }

        return ans;
    }
};
