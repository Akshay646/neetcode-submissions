class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols
        int minutes = 0;
        int fresh = 0;
        //add all rotten tomatoes first, becuase the also indicates a level
        //means those all rotten oranges rots neighbours on the same minute/level
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                //we count fresh, becuase if by bfs we were never able to rotten all
                //oranges, we should return -1;
                if(grid[i][j] == 1){fresh++;}
            }
        }
        vector<int> delRows = {0, 1, 0, -1};
        vector<int> delCols = {1, 0, -1, 0};

        //start BFS: All neighbouring oranges get rotten on the same level/minute
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                auto[r, c] = q.front();
                q.pop();
                //now rott/visit its neibours(u,d,l and r)
                for(int i = 0; i < 4; i++){
                    int nRow = r + delRows[i];
                    int nCol = c + delCols[i];

                    //nRow & nCol will give you all 4 directions, so process them
                    //make sure to handle boundary conditions
                    if(nRow < m && nRow >= 0 && nCol < n && nCol >= 0 && grid[nRow][nCol] == 1 /*this validates only fresh orange gets rotten and picked*/){
                        //mark them as wrotten
                        grid[nRow][nCol] = 2;
                        q.push({nRow, nCol});
                        //when u rott a fresh orange, reduce fresh by 1
                        fresh--;
                    }
                }
            }

            //if q is empty, means no level and so no minutes
            if(!q.empty()){
                minutes++;
            }
        }

        //now check, how many fresh elements your bfs was able to rott
        //if fresh becomes 0, means all oranges are rotten
        return fresh == 0 ? minutes : -1;
    }
};