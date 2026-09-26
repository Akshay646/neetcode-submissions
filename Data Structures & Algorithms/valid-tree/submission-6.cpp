class Solution {
public:
    bool IsCycle(int node, int parent, vector<vector<int>>& graph, vector<int>& seen){
        //mark visited
        seen[node] = true;

        //visit neighbours
        for(int nbr : graph[node]){
            //check if iys already visited
            if(!seen[nbr]){
                //also check of any earlier call has returned cycle
                if(IsCycle(nbr, node, graph, seen)){
                    return true;
                }
            }
            //check if cycle
            //nbr is already visited, and nbr is not the node from which the current
            //node was reached.
            else if(nbr != parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int totalEdges = edges.size();
        //this can not be a valid tree anyways as it might have cycle
        //or multiple connected componets
        if(totalEdges != n - 1){return false;}
        vector<vector<int>> adj(n);
        vector<int> seen(n, false);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //now check if cycle
        bool isCycle = IsCycle(0, -1, adj, seen);
        if(isCycle){return false;}

        //we still check if tree has multiple components which has not visited
        //if any node is not visited after abive dfs, ofc graph has mult. comps
        //and hence no valid tree
        for(int i = 0; i < n; i++){
            if(!seen[i]){
                return false;
            }
        }
        return true;
    }
};
