class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int correctRow = -1;

        int l = 0, r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (target < matrix[mid][0]) {
                r = mid;
            }
            else if (target > matrix[mid][m - 1]) {
                l = mid + 1;
            }
            else {
                correctRow = mid;
                break;
            }
        }

        // nie milne ka bhi possiblity h so we can't use mid
        if (correctRow == -1) return false;

        l = 0;
        r = m;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (matrix[correctRow][mid] == target)
                return true;
            else if (target < matrix[correctRow][mid])
                r = mid;
            else
                l = mid + 1;
        }

        return false;
    }
};