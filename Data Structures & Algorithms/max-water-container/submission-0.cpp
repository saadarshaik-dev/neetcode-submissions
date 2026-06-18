class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1;
        int maxWater = 0;

        while (left < right) {
            int currWater = (right-left)*min(heights[left], heights[right]);
            maxWater = max(maxWater, currWater);

            if (heights[left] <= heights[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};
