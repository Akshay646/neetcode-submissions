class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //We use map as adjacency list since nodes are not
        //linear numerics, multiset helps mantain ascending order
        //even with duplicates
        unordered_map<string, multiset<string>> adj;

        //form a graph
        for(auto ticket : tickets){
            string u = ticket[0];
            string v = ticket[1];
            adj[u].insert(v);
        }

        //This helps manage the processing of stations which has
        //no return edge: adj[node].size() == 0, means it has no
        //neighbours means no edges

        //Why stack? -> It helps tracks stations based on LIFO as
        //we need it to manage stations in correct order which
        //helps take care of stations which has not return edge
        stack<string> st;
        vector<string> ans; //stores the processed stations

        //we usually traverse all stations until stack is not empty
        //Since we put each station in stack, and stack makes sure
        //we cover all the station.
        
        //we add 'JFK as starting point in stack
        st.push("JFK");
        while(!st.empty()){
            //get the current station(node)
            string curStation = st.top();
            //now check if this station has no return edge
            if(adj[curStation].size() == 0){
                //Since it has no return edge, add it in ans
                //and remove from stack
                ans.push_back(curStation);
                st.pop();
            }
            //Else curStations has neighbours, just visit them
            else{
               //Since it has nbrs, take the first neighbour since
               //its lexically small
               auto it = adj[curStation].begin();
               //add it in stack to process
               st.push(*it);
               //since this neighbour(edge) is visisted, remove it
               //from adjacency list
               adj[curStation].erase(it);
            }
        }

        //since we have stored stations based the no return edges
        //reverse those to get correct order where stations with
        //return edges comes first and then with no edges
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
