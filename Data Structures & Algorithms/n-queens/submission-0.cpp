class Solution {
public:
    bool IsValidPlace(int r, int c, unordered_set<int>& cols,
    unordered_set<int>& nDiagonals, unordered_set<int>& pDiagonals){
        if(cols.count(c) || nDiagonals.count(r - c) || pDiagonals.count(r + c)){
            return false;
        }
        return true;
    }
    void backtrack(int row, vector<string>& board, 
    vector<vector<string>>& ans, unordered_set<int>& cols,
    unordered_set<int>& nDiagonals, unordered_set<int>& pDiagonals){
        //base cases + if the queen is already placed in same col or any of diagonals
        if(row == board.size()){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < board.size(); col++){
            if(!IsValidPlace(row, col, cols, nDiagonals, pDiagonals)){
                continue;
            }
            //mark col, and diagonals as visisted as u placed the queen
            cols.insert(col);
            nDiagonals.insert(row - col);
            pDiagonals.insert(row + col);
            board[row][col] = 'Q';
            backtrack(row + 1, board, ans, cols, nDiagonals, pDiagonals);
            //undo the choices after you return from happy path or invalid placements
            cols.erase(col);
            nDiagonals.erase(row - col);
            pDiagonals.erase(row + col);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); 
        unordered_set<int> cols;
        unordered_set<int> nDiagonals, pDiagonals;
        vector<vector<string>> ans;
        backtrack(0, board, ans, cols, nDiagonals, pDiagonals);
        return ans;
    }
};
