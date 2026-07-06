class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool subG[9][9] = {false};

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){continue;}
                //we would have done rows[i][rows[i][j] - '1'] also,
                //but its quite lenghty and complex
                //i helps tracks the column and tmpInd = tempNumInd helps tracks
                //which index we actually are setting the true/false
                int tmpInd = board[i][j] - '1';
                int subGInd = (i / 3) * 3 + (j / 3);
                if(rows[i][tmpInd] || cols[j][tmpInd] ||
                subG[subGInd][tmpInd]){
                    return false;
                }
                rows[i][tmpInd] = true; 
                cols[j][tmpInd] = true;
                subG[subGInd][tmpInd] = true;
            }
        }

        return true;
    }
};
