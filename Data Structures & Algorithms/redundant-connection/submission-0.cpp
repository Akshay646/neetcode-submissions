class Solution {
public:
    bool IsCycle(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited, set<pair<int, int>>& cyclicEdges, int& cycleStart){
        //visit node
        visited[node] = true;

        //traverse the neighbours
        for(int nbr : graph[node]){
            //chekc of its not visited
            if(!visited[nbr]){
                //now check if the cycle's found, true will be returned via overall path
                if(IsCycle(nbr, node, graph, visited, cyclicEdges, cycleStart)){
                    //we only keep adding cyclic edge till the cycle starting point
                    //after that, we can't return true as nodes before cycleStart were
                    //not part of cycle
                    if(node == cycleStart){
                        return false;
                    }
                    //Because your graph is undirected, it might store {5,3} while edges contains {3,5}.
                    //Normalise it -> cyclicEdges.insert({min(node, nbr),max(node, nbr) });           
                    cyclicEdges.insert({min(node, nbr), max(node, nbr) });           
                    return true;
                }

            }
            else if(nbr != parent){
/*                  1
                    |
                    2
                    |
                    3 --- 4
                    |     |
                    5 ----         */
                //->1 → 2 → 3 → 4 → 5 where 5 has neighbout 4 which is parent so ignore,
                //5 has also neighbour 3, which is not parent and also visited, found cycle. So the cycle strt becomes neghbour of 5 which is 3
                cycleStart = nbr;
                //found a cycle, store curren two edges and return true
                cyclicEdges.insert({min(node, nbr), max(node, nbr)});
                return true;
            }
        }

        //no cycle found - not possible based on current problem statement
        return false;
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
        bool iscycle = IsCycle(1, -1, adj, visited, cyclicEdges, cycleStart);

        //now cyclicEdges contains all the edges involve in cyclic portion of graph
        //since problem asks to return the edge which occurs last in input
        //we traverse input from last & return whatever edge matches from cyclicEdges
        //since all edges in cyclicEdges are part of cycle.
        vector<int> redundantConnection;
        for(int i = n - 1; i >= 0; i--){
            if(cyclicEdges.find({edges[i][0], edges[i][1]}) != cyclicEdges.end()){
                //we got the cyclic edge that is fro an end of given input edges
                redundantConnection.push_back(edges[i][0]);
                redundantConnection.push_back(edges[i][1]);
                break;
            }
        }

        return redundantConnection;
    }
};