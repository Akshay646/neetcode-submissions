class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        //{weight/distance, nodeInd}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        int minCost = 0;
        pq.push({0, 0}); //here 0 is minCost, 0 is index
        while(!pq.empty()){
            auto[curCost, node] = pq.top();
            pq.pop();

            //now make sure its not already visited, if we visit
            //such, it will cause incorrect costs and MST
            if(visited[node]){continue;}

            //if not visited, first store the cost
            //curCost is certainly min here since we always take
            //min cost element from queue
            minCost += curCost;
            //mark it as visited
            visited[node] = true;

            // Traverse all points (all are potential neighbours)
            for(int i = 0; i < points.size(); i++){
                if(!visited[i]){
                    //calcuate manhatten ditance
                    int dist = abs(points[node][0] - points[i][0]) 
                    + abs(points[node][1] - points[i][1]);

                    pq.push({dist, i});
                }
            }
        }
        return minCost;
    }
};
