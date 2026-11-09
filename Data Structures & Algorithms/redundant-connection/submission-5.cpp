class Solution {
public:
    bool IsCyclic(int node, int parent, vector<vector<int>>& adj, vector<bool>& seen, set<pair<int, int>>& cyclicEdges, int& cycleStart){
        seen[node] = true;
        //visit neighbours
        for(int nbr : adj[node]){
            if(!seen[nbr]){
                if(IsCyclic(nbr, node, adj, seen, cyclicEdges,
                cycleStart)){
                    cyclicEdges.insert({min(node, nbr), max(node, nbr)});
                    if(node == cycleStart){
                        return false;
                    }
                    return true;
                }
            }
            else if(nbr != parent){
                cout << "Cycle Here detects " << node << ", " << nbr << "\n";
                cyclicEdges.insert({min(node, nbr), max(node, nbr)});
                cycleStart = nbr;//since connecting node to
                //nbr causing the cycle henvce nbr's the start
                return true;
            }
        }
        return false;//no cycle found at all
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //for a graph, its bidirection based on statement
        //n + 1 since its 1 based
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //n + 1 since its 1 based
        vector<bool> seen(n + 1, false);
        set<pair<int, int>> cyclicEdges;
        int cycleStart = 0;
        bool ans = IsCyclic(1, -1, adj, seen, cyclicEdges,
                cycleStart);

        //DEBUG:
        for(auto [u,v] : cyclicEdges){
            cout << u << ", " << v << "\n";
        }

        //now if cycle is there, we can remove any edge to
        //make it a non-cyclic graph, but based on problem
        //statement, we need to make sure to remove the edge
        //which appears last in the input set
        for(int i = n - 1; i >= 0; i--){
            auto it = cyclicEdges.find({edges[i][0], edges[i][1]});
            if(it != cyclicEdges.end()){
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }
};
