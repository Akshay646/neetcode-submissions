class Solution {
public:
    bool backtrack(int r, int c, int i, vector<vector<char>>& board, string& word){
        //boundary checks
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size())return false;
        //invalid comparision check in case no point going further in that path
        if(board[r][c] != word[i])return false;
        //check if you're reaching at already visited cell
        if(board[r][c] == '#')return false;
        //if i reaches till word.size(), you have found the word in board
        if(i >= word.size() - 1)return true;

        //mark the cell visited for current path
        char stateBeforeBacktrack = board[r][c];
        board[r][c] = '#';
        bool isWordFound =  backtrack(r + 1, c, i + 1, board, word) ||
                            backtrack(r - 1, c, i + 1, board, word) ||
                            backtrack(r, c + 1, i + 1, board, word) ||
                            backtrack(r, c - 1, i + 1, board, word);

        if(isWordFound)return true;

        //backtrack the visited so the current cell can be visited by later paths
        board[r][c] = stateBeforeBacktrack;
        
        //if it never returns true anywhere, we never found the word in board
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
       //start from every word as there can be words as starting points which
       //does not have same char as word
       for(int r = 0; r < board.size(); r++){
        for(int c = 0; c < board[0].size(); c++){
            if(backtrack(r, c, 0, board, word)){
                return true;
            }
        }
       }
       return false;
    }
};
