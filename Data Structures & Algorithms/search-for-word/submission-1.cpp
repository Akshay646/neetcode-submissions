class Solution {
public:
    bool backtrack(int r, int c, int i, vector<vector<char>>& board, string& word){
        //1. Base case:
        //when you find the word
        if(i == word.size())return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()
        || i >= word.size() || board[r][c] != word[i] || board[r][c] == '#'){
            return false;
        }

        //2. Recurse & Backtrack
        //mark the cell as visisted
        char temp = board[r][c];
        board[r][c] = '#';
        bool found =backtrack(r + 1, c, i + 1, board, word) ||
                    backtrack(r - 1, c, i + 1, board, word) ||
                    backtrack(r, c + 1, i + 1, board, word) ||
                    backtrack(r, c - 1, i + 1, board, word);
        //backtrack: when you returns, restore the previous state
        board[r][c] =  temp;

        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(backtrack(i, j, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};
