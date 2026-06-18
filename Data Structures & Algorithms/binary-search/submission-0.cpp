class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (left >= right)
            return -1;
        
        int mid = left+(right-left)/2;
        
        if (target == nums[mid])
            return mid;
        
        else if (target < nums[mid])
            return binarySearch(nums, 0, mid, target);
        
        else
            return binarySearch(nums, mid+1, right, target);

    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size(), target);
    }
};
