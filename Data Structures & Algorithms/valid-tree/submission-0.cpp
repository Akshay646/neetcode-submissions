class Solution {
public:
    bool IsCyclic(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node] = true;
        //visit neighbours
        for(int nbr : graph[node]){
            //check if nbr is not visited
            if(!visited[nbr]){
                //check if cycle, return true
                if(IsCyclic(nbr, node, graph, visited)){
                    return true;
                }
            }
            else if(nbr != parent){
            //if its visited, also check if node and its
            //parents are different, if so, its cycle
            return true;

            }
        }
        return false; //no cycle found
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //a tree on n nodes has exactly n-1 edges.
        //more than n-1 => must contain a cycle
        //fewer than n-1 => must be disconnected
        if(edges.size() != n - 1){return false;}
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        //form a graph ; adj
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //now start from 0 and check if you can visit all nodes
        //if so, then its connected
        bool isCyclic = IsCyclic(0, -1, adj, visited);
        if(isCyclic){return false;}

        //Now we checked if its cyclic, starting from 0
        //if so its not valid tree.
        //but it still can have disconnected components
        //so if any of the node is not visited starting from 0,
        //it means those're disconnected, & so it can't be valid tree
        for(int i = 0; i < n; i++){
            //check if any node is not visited
            if(!visited[i]){
                //found disconnected component
                return false;
            }
        }

        //We neither find any disconnected component nor a cycle from
        //above all check, so its valid tree, hence return true;
        return true; 
    }
};
