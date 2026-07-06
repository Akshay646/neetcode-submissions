class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool subG[9][9] = {false};

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){continue;}
                // We could directly write rows[i][board[i][j] - '1'],
                // but storing the digit index in tmpInd improves readability.
                // 'digit' converts the character ('1' to '9') into an index (0 to 8).
                // The first index selects the current row/column/box,
                // and the second index selects the digit being checked.
                int digit = board[i][j] - '1';
                int subGInd = (i / 3) * 3 + (j / 3);
                if(rows[i][digit] || cols[j][digit] ||
                subG[subGInd][digit]){
                    return false;
                }
                rows[i][digit] = true; 
                cols[j][digit] = true;
                subG[subGInd][digit] = true;
            }
        }

        return true;
    }
};
