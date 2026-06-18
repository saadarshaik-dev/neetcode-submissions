class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> postfix(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            int j = 0;
            while(j < i) {
                prefix[i]*=nums[j];
                j++;
            }
            j = nums.size()-1;
            while(j > i) {
                postfix[i]*=nums[j];
                j--;
            }
        }

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(prefix[i]*postfix[i]);
        }

        return ans;
    }
};
