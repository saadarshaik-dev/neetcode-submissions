class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> mp;
        int n = position.size();
        int fleets = 0;
        double lastTime = 0;
        
        for (int i = 0; i < n; i++) {
            mp.push_back({position[i], speed[i]});
        }

        sort(mp.begin(), mp.end());

        for (int i = n-1; i >= 0; i--) {
            double arrivalTime = (double)(target-mp[i].first)/mp[i].second;
            if (arrivalTime > lastTime) {
                lastTime = arrivalTime;
                fleets++;
            }
        }

        return fleets;
    }
};
