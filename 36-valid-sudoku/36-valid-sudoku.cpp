class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9, unordered_set<int>()); //use hash set to check duplicates
        vector<unordered_set<int>> col(9, unordered_set<int>());
        vector<unordered_set<int>> subbox(9, unordered_set<int>());
        for (int i = 0; i < 9; i++) { 
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (row[i].insert(board[i][j]).second == false)
                    return false;
                if (col[j].insert(board[i][j]).second == false)
                    return false;
                int boxIndex = (i / 3) * 3 + j / 3;
                if (subbox[boxIndex].insert(board[i][j]).second == false && board[i][j] != '.')
                    return false;
            }
            row.clear();
        }
        return true;
    }
};