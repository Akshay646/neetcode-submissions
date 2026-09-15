class Solution {
public:
    bool backtrack(int r, int c, vector<vector<char>>& board, string word, int i, int m, int n){
        //modifying input set to avoid extra space for board, do not do in interviews
        //until clarified by interviewer
        if(r < 0 || r >= m || c < 0 || c >= n){return false;}
        if(board[r][c] == '#' || board[r][c] != word[i]){return false;}//it means its visited
        if(i == word.size() - 1){return true;}//we traversed all chars in word so, found

        //store current word before marking it visited so we can backtrack it(reassign)
        char tmp = board[r][c];
        board[r][c] = '#';

        //now check all directions
        if(backtrack(r + 1, c, board, word, i + 1, m, n) ||
            backtrack(r, c + 1, board, word, i + 1, m, n) ||
            backtrack(r - 1, c, board, word, i + 1, m, n) ||
            backtrack(r, c - 1, board, word, i + 1, m, n)
        ){
            return true;
        }

        //backtrack by reassigning marked choice
        board[r][c] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(backtrack(r, c, board, word, 0, m, n)){
                    return true;
                }
            }
        }
        return false;
    }
};
