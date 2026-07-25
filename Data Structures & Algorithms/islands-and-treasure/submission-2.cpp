class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //{{r,c},distance} we need distance w.r.t r,c to store the
        //subsequent distances starting from r and c
        queue<pair<pair<int, int>, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        
        //since we start from every treaure simultaneously
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 0){
                    //since these are starting points, distance=0
                    q.push({{r,c},0});
                }
            }
        }
        int dRows[4] = {0, 1, 0, -1};
        int dCols[4] = {1, 0, -1, 0};
        //Apply BFS simultaneously from all treasures
        while(!q.empty()){
            //process the current cell
            auto currCell = q.front();
            q.pop();
            auto [r, c] = currCell.first;
            int distance = currCell.second;

            //traverse its neighbours
            for(int i = 0; i < 4; i++){
                int nR = r + dRows[i];
                int nC = c + dCols[i];
                 //boundary check
                if(nR < 0 || nC < 0 || nR >= m || nC >= n)
                    continue;

                //If its water, then also continue
                if(grid[nR][nC] == -1)
                    continue;
                
                //if already visited
                if(grid[nR][nC] != INT_MAX)continue;

                //Now this is valid cell where INF is there
                //assign distance from the previous cell([r, c])
                // to its neighbours
                grid[nR][nC] = distance + 1;
                q.push({{nR, nC}, distance + 1});
            }
        }
    }
};
