class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& seen, queue<pair<int, int>>& q){
        int m = heights.size();
        int n = heights[0].size();

        int dR[4] = {0, 1, 0, -1};
        int dC[4] = {-1, 0, 1, 0};

        while(!q.empty()){
            //get the current cell to process
            auto [r, c] = q.front();
            q.pop();

            //now check its neighbours
            for(int i = 0; i < 4; i++){
                //all 4 directions one by one->traverse each neighbour
                int nR = dR[i] + r;
                int nC = dC[i] + c;

                //now check if neighbour cell is valid to be considered
                //check bourndary checks as well and if its already visited
                if(nR >= 0 && nR < m && nC >= 0 && nC < n && !seen[nR][nC] &&
                /*check if we can move forward from the cell
                above parent [r, c] cell becomes parent for [nR, nC] cell
                if hts[r][c] <= hts[nR][nC]->u can go frm parent to that neighbour*/
                heights[r][c] <= heights[nR][nC]){
                    q.push({nR, nC});
                    //mark this neighbour cell as visited
                    seen[nR][nC] = true;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false)),
                             atlantic(m, vector<bool>(n, false));

        //we start from both ocean's edge elements at once
        queue<pair<int, int>> q; //{r, c}

        //top edge - pacific
        for(int c = 0; c < n; c++){
            q.push({0, c});
            pacific[0][c] = true;
        }
        //left edge - pacific
        for(int r = 0; r < m; r++){
            q.push({r, 0});
            pacific[r][0] = true;
        }
         //for pacific traversal
        bfs(heights, pacific, q);

        //now refresh the queue
        q = queue<pair<int, int>>();
        //bottom edge - atlantic
        for(int c = 0; c < n; c++){
            q.push({m - 1, c});
            atlantic[m - 1][c] = true;
        }
        //right edge - atlantic
        for(int r = 0; r < m; r++){
            q.push({r, n - 1});
            atlantic[r][n - 1] = true;
        }
       
        //for atlatic traversal
        bfs(heights, atlantic, q);

        //now check, if a cell is visited for both of the traversal, it means
        //water flows to both the oceals from that cell
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};
