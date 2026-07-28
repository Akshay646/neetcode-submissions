class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        //Add all '0' cells apart from the cells which are at boundaries
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                //we only care about 'O' cells which are on the edge
                if (board[r][c] == 'O' &&
                (r == 0 || c == 0 || r == m - 1 || c == n - 1))
                {
                    q.push({r, c});
                    seen[r][c] = true;
                }
            }
        }
       
        //Using BFS, just mark all the cells True whichever are reachable from these
        //cells on the edge
        while(!q.empty()){
            auto[r, c] = q.front();
            q.pop();

            int dR[4] = {0, 1, 0, -1};
            int dC[4] = {1, 0, -1, 0};

            for(int i = 0; i < 4; i++){
                int nR = r + dR[i];
                int nC = c + dC[i];

                //we only care about the cells which are 'O'
                if(nR >= 0 && nC >= 0 && nR < m && nC < n && !seen[nR][nC] && board[nR][nC] == 'O'){
                    q.push({nR, nC});
                    seen[nR][nC] = true;
                }
            }
        }
        
        //Then traverse the board, and check for every cell [r, c],
        //If it marked as not visited in seen and its 'O' at board, 
        //mark it as 'X'
         for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(board[r][c] == 'O' && !seen[r][c]){
                    board[r][c] = 'X';
                }
            }
         }
    }
};