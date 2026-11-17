class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //pq = {cost, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
        int n = points.size();
        vector<bool> seenInMST(n);
        int minCost = 0;

        //start from 0th point
        pq.push({0, 0});
        while(!pq.empty()){
            //get the current element
            //here node is an index of the point
            auto[cost, node] = pq.top();
            pq.pop();

            //do not add cost if its already a part of MST
            if(seenInMST[node]){continue;}

            //Mark as seen in MST
            seenInMST[node] = true;
            //Now add the cost
            minCost += cost;

            //now, all points are current node's neighbours, so
            //traverse them all
            for(int nbr = 0; nbr < points.size(); nbr++){
                int dist = abs(points[node][0] - points[nbr][0]) 
                + abs(points[node][1] - points[nbr][1]);

                if(!seenInMST[nbr]){
                    pq.push({dist, nbr});
                }
            }
        }
        return minCost;
    }
};
