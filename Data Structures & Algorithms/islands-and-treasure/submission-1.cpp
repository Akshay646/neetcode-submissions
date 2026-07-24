class Solution {
public:
    int GetMinDistance(int _r, int _c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        //Seen should be local to BFS, if you make it shared
        //it will mark all cells visited at first BFS call, so rest BFS
        //calls will not even  execute
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q; //{{row, col}, distance}
        q.push({{_r, _c}, 0});
        //mark starting node as visited
        seen[_r][_c] = true;

        int dRows[4] = {0, 1, 0, -1};
        int dCols[4] = {1, 0, -1, 0};
        
        while(!q.empty()){
            //get the current cell out of the queue
            auto cell = q.front();
            q.pop();
            auto [r, c] = cell.first;
            int dis = cell.second;
            if(grid[r][c] == 0){
                return dis;
            }

            //visit neighbours
            for(int i = 0 ; i < 4; i++){
                int nR = r + dRows[i];
                int nC = c + dCols[i];

                //boundary check
                if(nR < 0 || nC < 0 || nR >= m || nC >= n)
                    continue;
                //If its water, then also continue
                if(grid[nR][nC] == -1)
                    continue;
                
                //if already visited
                if(seen[nR][nC])continue;

                //Now this is valid cell where INF is there
                q.push({{nR, nC}, dis + 1});
                seen[nR][nC] = true;
            }
        }
        return INT_MAX;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //Apply BFS for every INF value and keep updating it with
        //min distance with respective to the cell
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == INT_MAX){
                    int distance = GetMinDistance(i, j, grid);
                    grid[i][j] = distance;
                }
            }
        }
    }
};
