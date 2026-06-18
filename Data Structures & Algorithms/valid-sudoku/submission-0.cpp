class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
        }
    };
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowSize = board.size();
        int colSize = board[0].size();

        //unordered_map<int, int> rowMap, colMap, miniBoxMap;

        for (int i = 0; i < rowSize; i++) {
            unordered_map<int, int> colMap;
            for (int j = 0; j < colSize; j++) {
                if (board[i][j] == '.') continue;
                if (colMap.find(board[i][j]) != colMap.end())
                    return false;
                colMap[board[i][j]] = 1;
            }
        }

        for (int j = 0; j < colSize; j++) {
            unordered_map<int, int> rowMap;
            for (int i = 0; i < rowSize; i++) {
                if (board[i][j] == '.') continue;
                if (rowMap.find(board[i][j]) != rowMap.end())
                    return false;
                rowMap[board[i][j]] = 1;
            }
        }

        //unordered_map<int, int> boxMap;

        unordered_map<pair<int, int>, unordered_map<int, int>, PairHash> boxNumMap; 

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (board[i][j] == '.') continue;
                int newi = i/3, newj = j/3;
                boxNumMap[make_pair(newi, newj)];
                if (boxNumMap[make_pair(newi, newj)].find(board[i][j])!=boxNumMap[make_pair(newi, newj)].end())
                    return false;
                boxNumMap[make_pair(newi, newj)][board[i][j]] = 1;
            }
        }

        return true;
    }
};
