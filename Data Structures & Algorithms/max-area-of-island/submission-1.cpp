class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& seen,
     int& area){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || seen[i][j] || grid[i][j] == 0){
            return;
        }
        seen[i][j] = true;
        area++;
        dfs(i + 1, j, grid, seen, area);
        dfs(i - 1, j, grid, seen, area);
        dfs(i, j + 1, grid, seen, area);
        dfs(i, j - 1, grid, seen, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        //call dfs only on cells which has 1(land)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !seen[i][j]){
                    int area = 0;
                    dfs(i, j, grid, seen, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};