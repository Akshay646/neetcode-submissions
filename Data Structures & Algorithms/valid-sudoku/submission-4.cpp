class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       bool rows[9][9] = {false};
       bool cols[9][9] = {false};
       bool blocks[9][9] = {false};
       int n = board.size();

       for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            //we do not care for '.'
            if(board[i][j] == '.')continue;
            //get the ascii converted index(0 to 9)
            int num = board[i][j] - '1';

            //get block index
            int bInd = (i/3) * 3 + (j/3);

            //check if for any row/col/bloack with respect to num is alreadt set true
            if(rows[i][num] || cols[j][num] || blocks[bInd][num]){
                return false;
            }

            //else, for given num, set each position as true;
            //means num(i.e index) is seen at given row, col & block
            rows[i][num] = cols[j][num] = blocks[bInd][num] = true;
        }
       }

       return true;
    }
};
