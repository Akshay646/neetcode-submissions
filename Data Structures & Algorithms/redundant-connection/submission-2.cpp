class Solution {
public:
    bool IsCycle(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited, set<pair<int, int>>& cycliclEdges, int& cycleStart){
        visited[node] = true;

        //visit neighbours
        for(int nbr : graph[node]){
            //check if visited
            if(!visited[nbr]){
                bool cycle = IsCycle(nbr, node, graph, visited, cycliclEdges, cycleStart);
                if(cycle){
                    cycliclEdges.insert({min(node, nbr), max(node, nbr)});

                    // Once we reach the starting node of the cycle,
                    // stop propagating the cycle back to its ancestors.
                    if(node == cycleStart){
                        return false;
                    }

                    //make sure you return true becuase otheriwse its a cycle and its
                    //previous nodes which are part of cycle should also be considered
                    return true;
                }
            }
            else if(nbr != parent){//deteted cycle since nbr != parent
                cycliclEdges.insert({min(node, nbr), max(node, nbr)});
                cycleStart = nbr;
                return true;
            }
        }
        return false; //no cycle found; but this will not execute as cycle will exist
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1, false);
        set<pair<int, int>> cycliclEdges;

        //form a graph
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cycleStart = 0;
        bool isCycle = IsCycle(1, -1, adj, visited, cycliclEdges, cycleStart);

        //check from back of inout array as they want edge to be removed which
        //appears last in input if multiple valid answers

        for(int i = n - 1; i >= 0; i--){
            auto it = cycliclEdges.find({edges[i][0], edges[i][1]});
            if(it != cycliclEdges.end()){
                return {it->first, it->second};
            }
        }

        return {};
    }
};
