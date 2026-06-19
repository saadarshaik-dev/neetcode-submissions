class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mn = INT_MAX;

        while (l < r) {
            int mid = (l+r)/2;

            mn = min(nums[mid], mn);

            //search right
            if (nums[mid] > nums[r]) {
                l = mid+1;
            }

            //search left
            else
                r = mid;
        }

        mn = min(mn, nums[l]);

        return mn;
    }
};
