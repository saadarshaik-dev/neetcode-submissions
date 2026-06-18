class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> unique;

        for (int i = 0; i < n; i++) {
            int left = i+1;
            int right = n-1;

            while (left < right && left < n && right > i) {
                int currSum = nums[left] + nums[right] + nums[i];

                if (currSum == 0) {
                    unique.insert({nums[left], nums[right], nums[i]});
                    left++;
                }
                else if (currSum < 0)
                    left++;
                else
                    right--;
            }
        }

        for (auto i : unique)
            ans.push_back(i);

        return ans;
    }
};
