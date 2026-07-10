class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& seen){
        //boundary conditions check
        //also if its seen already, or if water i.e. '0', then also discontinue
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || seen[i][j]
        || grid[i][j] == '0'){
            return;
        }
        //you have visited the cell
        seen[i][j]= true;
        dfs(i - 1, j, grid, seen);
        dfs(i + 1, j, grid, seen);
        dfs(i, j + 1, grid, seen);
        dfs(i, j - 1, grid, seen);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //seen helps track the number of connected components
                //otherwise seen elements can also be treat as valid start point
                //to form connected componet
                //Also, only start dfs if its land i.e. '1'
                if(grid[i][j] == '1' && !seen[i][j]){
                    //dfs helps traverse only connected cells and mark them visited
                    dfs(i, j, grid, seen);
                    islands++;
                }
            }
        }
        return islands;
    }
};
