class Solution {
public:
    bool IsCycleExist(int node, vector<bool>& visited, vector<bool>& pathVis,
    vector<vector<int>>& adj){
        visited[node] = true;
        pathVis[node] = true;
        //visit neighbours
        for(auto& nbr : adj[node]){
            if(!visited[nbr]){
                if(IsCycleExist(nbr, visited, pathVis, adj)){
                    return true;
                }
            }
            else if(pathVis[nbr]){
                return true;
            }
        }

        //backtrack:
        //because, the same node might be visited by different recursion path
        //and if we do remove it fromcurrent path after returning,
        //it will cause false cycle detection
        pathVis[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& p : prerequisites){
            //since you must take v before u 
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        
        //since a graph can be disconnected, we alway traverse
        //through all of the courses
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(IsCycleExist(i, visited, pathVis, adj)){
                    //cycle existed, so you can not finish the all courses
                    return false;
                }
            }
        }
        //since no cycle exist, you can finish all the courses
        return true;
    }
};
