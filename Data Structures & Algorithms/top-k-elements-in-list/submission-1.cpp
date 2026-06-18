class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> bucket(nums.size()+1, vector<int>{});
        map<int, int> count;

        for (int i : nums) {
            count[i]++;
        }

        for (auto [i, j] : count) {
            bucket[j].push_back(i); 
        }

        vector<int> ans;

        while (k > 0) {
            for (int j = nums.size(); j > 0; j--) {
                if (bucket[j].size() != 0) {
                    int itr = bucket[j].size()-1;
                    while (itr > -1 && k > 0) {
                        ans.push_back(bucket[j][itr]);
                        k--;
                        itr--;
                    }
                }
            }
        }
        return ans;
    }
};
