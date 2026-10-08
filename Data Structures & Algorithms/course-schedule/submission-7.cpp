class Solution {
public:
    bool IsCycle(int node, vector<vector<int>>& graph, vector<bool>& seen, vector<bool>& pathSeen){
        seen[node] = true;
        pathSeen[node] = true;

        //visit neighbours
        for(int nbr : graph[node]){
            if(!seen[nbr]){
                if(IsCycle(nbr, graph, seen, pathSeen)){
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

        //here means no cycle found
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> pathSeen(numCourses);
        vector<bool> seen(numCourses);
        vector<vector<int>> graph(numCourses);

        for(auto& preq : prerequisites){
            int u = preq[0];
            int v = preq[1];
            graph[v].push_back(u);
        }

        //check cycle with or withoutof diconnected components
        for(int i = 0; i < numCourses; i++){
            if(!seen[i]){
                if(IsCycle(i, graph, seen, pathSeen)){
                    return false;
                }
            }
        }
        return true;
    }
};
