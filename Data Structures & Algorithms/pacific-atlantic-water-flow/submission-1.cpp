class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights,
    bool& pacific, bool& atlantic, vector<vector<bool>>& seen){
        int m = heights.size();
        int n = heights[0].size();
        //if visited, return
        if(seen[r][c])return;

        seen[r][c] = true;
        //if your r or c touches 0; reaches pacific ocean
        if(r == 0 || c == 0)
            pacific = true;
        if(r == m - 1 || c == n - 1)
            atlantic = true;

        //visit all 4 directions
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++){
            //get all directions(neighbours)
            int nr = r + dr[k];
            int nc = c + dc[k];

            //only cal dfs, if currentheight([nr][nc]) < prevheight[r][c]
            //and boundary checks are valid
            if(nr < m && nc < n && nc >= 0 && nr >= 0 &&
            !seen[nr][nc] && heights[nr][nc] <= heights[r][c]){
                dfs(nr, nc, heights, pacific, atlantic, seen);
            }
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
            //we declare these two here as we check for every cell
            bool pacific = false, atlantic = false;
            vector<vector<bool>> seen(m, vector<bool>(n, false));
               dfs(r, c, heights, pacific, atlantic, seen);
               //if both pacific and atlantic are true,means current
               //r & c cell reaches both the ends
               if(pacific && atlantic){
                ans.push_back({r, c});
               }
            }
        }
        return ans;
    }
};
