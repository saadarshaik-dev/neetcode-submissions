class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numList;

        for (int x : nums) {
            if (numList.find(x) != numList.end())
                return true;
            else
                numList.insert(x);
        }

        return false;
    }
};