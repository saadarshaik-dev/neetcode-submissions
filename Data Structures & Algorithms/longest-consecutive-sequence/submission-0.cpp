class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end()); //to avoid duplicates
        int mxCount = 0;

        for (int x : s) {
            int count = 0;
            if (s.find(x-1) == s.end()) {
                int curr = x;
                count++;
                while(s.find(curr+1) != s.end()) {
                    count++;
                    curr++;
                }
            }
            mxCount = max(count, mxCount);
        }

        return mxCount;
    }
};
