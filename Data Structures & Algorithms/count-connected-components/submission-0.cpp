class Solution {
public:
    void BFS(int stNode, vector<vector<int>>& graph, vector<bool>& visited){
        queue<int> q;
        q.push(stNode);
        //mark the stNode as visited since we actually visited
        visited[stNode] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            //visit neighbours of the node
            for(int nbr : graph[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    //since you visited the neighbour, mark it visited
                    visited[nbr] = true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int totalComponents = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        //form a graph
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //visit each node
        for(int i = 0; i < n; i++){
            //only call BFS on unvisited nodes
            if(!visited[i]){
                BFS(i, adj, visited);
                //Every time we start a NEW DFS/BFS, we found a NEW component.
                totalComponents += 1;
            }
        }
        return totalComponents;
    }
};
