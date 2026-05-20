class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();

        //row pass
        for(int i = 0; i < m; i++)
        {
            unordered_set<char> s1;
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == '.'){continue;}
                if(!s1.count(board[i][j]))
                {
                    s1.insert(board[i][j]);
                }
                else
                {
                    return false; //early exit
                }
            }
        }

        //column pass
        for(int i = 0; i < m; i++)
        {
            unordered_set<char> s2;
            for(int j = 0; j < m; j++)
            {
                if(board[j][i] == '.'){continue;}
                if(!s2.count(board[j][i]))
                {
                    s2.insert(board[j][i]);
                }
                else
                {
                    return false; //early exit
                }
            }
        }

        //subgrid pass
        int bSize = sqrt(m);
        for(int k = 0; k < m; k++)
        {
            int br = k / bSize; // => gives the row block number
            int bc = k % bSize; // => gives the column block number

            int sr = br * bSize; //=> gives the starting row of that block
            int sc = bc * bSize; //=? gives the starting column of that block
            unordered_set<char> s3;
            for(int i = sr; i < sr + bSize; i++)
            {
                for(int j = sc; j < sc + bSize; j++)
                {
                    if(board[i][j] == '.'){continue;}
                    if(!s3.count(board[i][j]))
                    {
                        s3.insert(board[i][j]);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        //It means every three conditions are satified. i.e unique elements
            return true;
    }
};
