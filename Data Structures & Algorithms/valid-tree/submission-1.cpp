class Solution {
public:
    bool IsCycle(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node] = true;
        for(int nbr : graph[node]){
            if(!visited[nbr]){
                if(IsCycle(nbr, node, graph, visited)){
                    return true;
                }
            }
            else if(nbr != parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        
        if(e == n)return false;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool cycle = IsCycle(0, -1, graph, visited);

        //now check if since you started from 0, if visited all nodes
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                //since it is diconnected graph, and it can not be a valid tree
                return false;
            }
        }

        return true; //since all nodes are visited and hence connected
    }
};
