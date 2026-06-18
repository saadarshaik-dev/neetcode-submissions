class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int i : nums) {
            count[i]++;
        }

        auto cmp = [&count](int a, int b){
            return count[a] < count[b];
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (auto& [num, freq] : count) {
            pq.push(num);
        }

        vector<int> ans;

        for(int j = 0; j < k; j++) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
