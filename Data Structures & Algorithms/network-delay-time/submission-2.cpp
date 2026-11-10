class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);

        for(auto t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v, w});
        }
        int nwDTime = 0;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            //get the current node
            auto [pDist, pNode] = pq.top();
            pq.pop();

            //traverse the neighbours
            for(auto [nbrNode, nbrDist] : adj[pNode]){
                //we only care to store the distane from node
                //nbr node if exisiting nbrNode's distance is
                //smaller than current. This also avoid
                //revisiting the same node twice
                if(pDist + nbrDist < dist[nbrNode]){
                    dist[nbrNode] = pDist + nbrDist;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }

        //now we store min distances from k to all nodes, we
        //the max among them is what takes to cover all the
        //nodes
        //why from 1st index? Bcoz nodes starts from 1, so 0's
        //distance anyways does not matter
        nwDTime = *max_element(dist.begin() + 1, dist.end());
        return nwDTime == INT_MAX ? -1 : nwDTime;
    }
};
