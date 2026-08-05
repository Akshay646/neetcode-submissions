class Solution {
public:
    bool IsCycleExist(int node, vector<vector<int>>& graph, 
    vector<int>& state, vector<int>& topoSort){
        //visit the node and mark visited. 
        // state:
        // 0 = Unvisited
        // 1 = Visiting (currently in recursion stack)
        // 2 = Visited (fully processed)
        state[node]= 1;
        
        //now traverse neighbours
        for(int nbr : graph[node]){
            //if its not visited
            if(state[nbr] == 0){
                //if by any previous calls if it had return true
                //due to cycle was detected
                if(IsCycleExist(nbr, graph, state, topoSort)){
                    return true;
                }
            }//check if the node is revisiting in the same path
            //as it must have been previously marked as 1(from the same
            //path and not from different)
            //Becuase once we complete a path,we always change state of
            //that node to 2 means its completely visited and never comes
            //as 1 here
            else if(state[nbr] == 1){//if cycle exist
                return true;
            }
        }

        // All neighbors have been processed.
        // Mark current node as fully processed.
        state[node] = 2;

        // Store current node in postorder.
        // Reversing later gives a valid topological order.
        topoSort.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0);//initially unvisited
        vector<int> topoSort;

        //create a graph by given input
        for(auto p : prerequisites){
            int u = p[0];
            int v = p[1];
            //since v must be take before u
            adj[v].push_back(u);
        }

        //since there can be disconnected graphs,we always try from every
        //node which is not visited
        for(int i = 0; i < numCourses; i++){

            //becuase we can not return result right after we get
            //first occurence where cycle does not exist,as there
            //might be disconnected components which may be missed
            if(state[i] == 0 && IsCycleExist(i, adj, state, topoSort)){
                return {};
            }
        }
        reverse(topoSort.begin(), topoSort.end());
        return topoSort;
    }
};
