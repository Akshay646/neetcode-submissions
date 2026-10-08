class Solution {
public:
//this function not only checks cycle but also store topological order of nodes
    bool IsCycle(int node, vector<vector<int>>& graph, vector<bool>& seen, vector<bool>& pathSeen, vector<int>& topoOrder){
        seen[node] = true;
        pathSeen[node] = true;

        //visit neighbours
        for(int nbr : graph[node]){
            if(!seen[nbr]){
                if(IsCycle(nbr, graph, seen, pathSeen, topoOrder)){
                    return true;
                }
            }
            else if(pathSeen[nbr]){
                return true;
            }
        }
        // since a node can be visisted from multiple recursion branch, remove
        //that from current path while returning
        pathSeen[node] = false;

        //once all the nodes are visited based on their finishing prerequisites,
        //those are ready to add in the topo order since there was not cycle and
        //we able to finish those
        topoOrder.push_back(node);

        //here means no cycle found
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> pathSeen(numCourses);
        vector<bool> seen(numCourses);
        vector<vector<int>> graph(numCourses);
        vector<int> topoOrder;

        for(auto& preq : prerequisites){
            int u = preq[0];
            int v = preq[1];
            graph[v].push_back(u);
        }

        //check cycle with or withoutof diconnected components
        for(int i = 0; i < numCourses; i++){
            if(!seen[i]){
                if(IsCycle(i, graph, seen, pathSeen, topoOrder)){
                    return {};
                }
            }
        }

        reverse(topoOrder.begin(), topoOrder.end());
        return topoOrder;
    }
};
