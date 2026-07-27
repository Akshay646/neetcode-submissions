class Solution {
public:
    void dfs(int r, int c,
         int prevHeight,
         vector<vector<int>>& heights,
         vector<vector<bool>>& seen,
         bool& pacific,
         bool& atlantic)
{
    int m = heights.size();
    int n = heights[0].size();

    // Boundary
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    // Already visited
    if (seen[r][c])
        return;

    // Water can't flow uphill
    if (heights[r][c] > prevHeight)
        return;

    seen[r][c] = true;

    if (r == 0 || c == 0) pacific = true;
    if (r == m - 1 || c == n - 1) atlantic = true;

    dfs(r + 1, c, heights[r][c], heights, seen, pacific, atlantic);
    dfs(r - 1, c, heights[r][c], heights, seen, pacific, atlantic);
    dfs(r, c + 1, heights[r][c], heights, seen, pacific, atlantic);
    dfs(r, c - 1, heights[r][c], heights, seen, pacific, atlantic);
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
               dfs(r, c, heights[r][c], heights, seen, pacific, atlantic);
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
