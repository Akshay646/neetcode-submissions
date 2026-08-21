class Solution {
public:
    bool GetCyclicEdges(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited, set<pair<int, int>>& cyclicEdges, int& cycleStart){
        visited[node] = true;

        //visit neighbours
        for(int nbr : graph[node]){
            if(!visited[nbr]){
                bool IsCycle = GetCyclicEdges(nbr, node, graph,
                visited, cyclicEdges, cycleStart);
                //now check if is cycle
                if(IsCycle){
                    //if its cycle and nbr is one who's starting point
                    //this will help only adding nodes until the cycle
                    //started and then since it return false, the
                    //nodes which are not part of cycle will not get
                    //added
                    if(node == cycleStart){return false;}
                    cyclicEdges.insert({min(node, nbr), max(node, nbr) });
                    return true;//since its cycle otherwise
                }
            }
            else if(nbr != parent){
                //means cycle has found
                //store the cyclic node, and return true
                cyclicEdges.insert({min(node, nbr), max(node, nbr) });
                cycleStart = nbr;
                return true;
            }
        }
        return false; //no cycle found
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<bool> visited(n + 1, false);
        vector<vector<int>> adj(n + 1);
        //form a graph
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        set<pair<int, int>> cyclicEdges;
        int cycleStart = 0;
        bool isCycle = GetCyclicEdges(1, -1, adj, visited,
        cyclicEdges, cycleStart);

        //now traverse input edges from back since problem asks
        //if there are multiple answers, return the edge that appears
        //last in the input edges.
        for(int i = n - 1; i >= 0; i--){
            auto it = cyclicEdges.find({edges[i][0], edges[i][1]});
            if(it != cyclicEdges.end()){
                return {it->first, it->second};
            }
        }

        //defualt which will never be returned since guaranteed answer
        //exist
        return {0, 0};
    }
};
