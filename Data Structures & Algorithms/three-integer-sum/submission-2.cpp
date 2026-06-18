class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right = n-1;

            while (left < right && left < n && right > i) {
                int currSum = nums[left] + nums[right] + nums[i];

                if (currSum == 0) {
                    ans.push_back({nums[left], nums[right], nums[i]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (currSum < 0)
                    left++;
                else
                    right--;
            }
        }

        return ans;
    }
};
