class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();

        bool row [9][9] = {false};
        bool col [9][9] = {false};
        bool box [9][9] = {false};

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //if its '.', just continue
                if (board[i][j] == '.') continue;
                //now we check if this element is previously were seen
                //at any of the row, col or box
                int num = board[i][j] - '1';
                //i/3 gives row block no. and j/3 col block no. if you multiply
                //and and add 3, will give you exact index in that particulat block
                int bInd = (i / 3) * 3 + (j / 3);

                //now verify if its already see in any of the above
                if(row[i][num] || col[j][num] || box[bInd][num])
                {
                    return false;
                }
                //else, set them as seen
                row[i][num] = col[j][num] = box[bInd][num] = true;
            }
        }
        return true;
    }
};
