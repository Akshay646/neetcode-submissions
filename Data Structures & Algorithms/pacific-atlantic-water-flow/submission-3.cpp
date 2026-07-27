class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& seen, int prevheight){
        int m = heights.size();
        int n = heights[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n)return;
        if(seen[r][c])return;
        //Also, if current cell > prev cell, it means water can not
        //travel as we are now going backward
        if(heights[r][c] < prevheight)return;
        //mark current cell visited
        seen[r][c] = true;

        //since all validations are handled, we are not at valid cell. Explore all 4 neighbouring cells
        //you current hieght will become prevHeighT 
        dfs(r + 1, c, heights, seen, heights[r][c]);
        dfs(r - 1, c, heights, seen, heights[r][c]);
        dfs(r, c + 1, heights, seen, heights[r][c]);
        dfs(r, c - 1, heights, seen, heights[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        //Start Multisource DFS
        vector<vector<bool>> seenInPacific(m, vector<bool>(n, false));
        vector<vector<bool>> seenInAtlantic(m, vector<bool>(n, false));
        //-------DFS on Pacific Ocean---------------------
        //Top row : row stays put, col changes
        for(int c = 0; c < n; c++){
            dfs(0, c, heights, seenInPacific, heights[0][c]);
        }
         //Left col : col stays put, row changes
        for(int r = 0; r < m; r++){
            dfs(r, 0, heights, seenInPacific, heights[r][0]);
        }

         //-------DFS on Atlanctic Ocean---------------------
        //right last col : col stays put, row changes
        for(int r = 0; r < m; r++){
            dfs(r, n - 1, heights, seenInAtlantic, heights[r][n - 1]);
        }
         //bottom row : row stays put, col changes
        for(int c = 0; c < n; c++){
            dfs(m - 1, c, heights, seenInAtlantic, heights[m - 1][c]);
        }

        //Now check the cells which are present at both the visited
        //arrays, those are the cells which water can flow to both
        //the oceans
        vector<vector<int>> ans;
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(seenInPacific[r][c] && seenInAtlantic[r][c]){
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};