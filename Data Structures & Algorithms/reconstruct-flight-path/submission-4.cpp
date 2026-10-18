class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //We use map as adjacency list since nodes are not
        //linear numerics, multiset helps maintain ascending order
        //even with duplicates
        unordered_map<string, multiset<string>> adj;

        //form a graph
        for(auto ticket : tickets){
            string u = ticket[0];
            string v = ticket[1];
            adj[u].insert(v);
        }

        //Why stack? -> It helps us backtrack to the previous station
        //when we reach a station with no remaining outgoing edges.
        //We keep processing tickets from the current station and
        //add a station to ans only when it has no outgoing edges left.
        //This makes sure we explore the available route before adding
        //the station to ans

        stack<string> st;
        vector<string> ans; //stores the processed stations

        //we add 'JFK as starting point in stack
        st.push("JFK");

        //we traverse until stack is not empty
        while(!st.empty()){
            //get the current station(node)
            string curStation = st.top();

            //now check if this station has no remaining outgoing edges
            if(adj[curStation].size() == 0){
                //Since it has no remaining outgoing edges, add it in ans
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

               //since this ticket(edge) is visited, remove it
               //from adjacency list
               adj[curStation].erase(it);
            }
        }

        //since we add stations to ans only after they have no
        //remaining outgoing edges, they get stored in reverse
        //itinerary order, so reverse ans to get the correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};