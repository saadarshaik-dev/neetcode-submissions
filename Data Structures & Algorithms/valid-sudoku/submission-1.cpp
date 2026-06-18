class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {};
        bool col[9][10] = {};
        bool box[9][10] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';

                int newi = i/3, newj = j/3;
                int boxIdx = newi*3+newj;

                if (row[i][num] || col[j][num] || box[boxIdx][num])
                    return false;

                row[i][num] = col[j][num] = box[boxIdx][num]= true;
            }
        }

        return true;

    }

};
