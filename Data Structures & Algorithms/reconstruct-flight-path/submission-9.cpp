class Solution {
public:
    void dfs(string node, unordered_map<string, multiset<string>>& adj, vector<string>& itinerary){
        while(!adj[node].empty()){
            //since lex smaller element always sits at front in
            //multiset
            auto itr = adj[node].begin();
            string nbr = *itr;
            //since we visit the neighbour, remove it from
            //multiset so we do not revisit it
            adj[node].erase(itr);
            //call dfs on its neighbours as usual
            dfs(nbr, adj, itinerary);
        }
        //This will execute only when no outgoing edges, means
        //the node as being pareng doesn't have neighbours, it
        //indicates, no outgoing edges to node back to others
        itinerary.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, multiset<string>> adj;
        for(auto ticket : tickets){
            string u = ticket[0];
            string v = ticket[1];
            adj[u].insert(v);
        }

        vector<string> itinerary;
        dfs("JFK", adj, itinerary);
        //To make sure we first traverse nodes with both incoming
        //and outgoing edges when other node doesn't have outgoing
        //edges irrespective of being lexically smaller, we need
        //to reverse the resultant array
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};