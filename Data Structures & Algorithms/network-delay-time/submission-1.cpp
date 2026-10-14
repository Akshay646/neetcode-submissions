class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>> pq; //{dist, node}
        vector<int> dist(n + 1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n + 1); //1 based graph
        for(vector<int>& time : times){
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v, t});
        }

        //mark the source node to process and make sure its distance
        //is 0. i.e. distance of src node to itself is 0
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            //get the current node to process
            auto[pDist, pNode] = pq.top();
            pq.pop();

            //now visit neighbours
            for(auto [nbrNode, nbrDist] : adj[pNode]){
                if(pDist + nbrDist < dist[nbrNode]){
                    dist[nbrNode] = pDist + nbrDist;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }

        //now there are couple of factors which makes the answer -1. 
        //If disconnected graph, means some of the dist would still
        //have INF set as we never reached that node from src node
        //Since dist contails minimum time from src to all nodes, the
        //max in all distacce is what we need to cover all nodes
        int nDTime = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            nDTime = max(nDTime, dist[i]);
        }
        return nDTime;
    }
};
