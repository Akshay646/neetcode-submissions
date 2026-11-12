class Solution {
public:
    void dfs(string node, unordered_map<string, multiset<string>>& adj,
             vector<string>& itinerary) {

        while (!adj[node].empty()) {

            // Since it's a multiset, the lexicographically smallest
            // destination is always at the beginning.
            auto itr = adj[node].begin();
            string nbr = *itr;

            // We've used this ticket, so remove it from the multiset
            // to make sure we don't traverse the same ticket again.
            adj[node].erase(itr);

            // Move to the neighbour and explore its outgoing tickets.
            dfs(nbr, adj, itinerary);
        }

        // We reach here only when the current node has no remaining
        // outgoing tickets. All its outgoing tickets have been used.
        // So, add this node to the itinerary.
        itinerary.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, multiset<string>> adj;

        for (auto ticket : tickets) {
            string u = ticket[0];
            string v = ticket[1];
            adj[u].insert(v);
        }

        vector<string> itinerary;

        dfs("JFK", adj, itinerary);

        // Since we add a node only after exploring all its outgoing
        // tickets, a lexicographically smaller destination that has
        // no outgoing tickets might get added before other parts
        // of the itinerary are completed.
        // Reversing puts these nodes in their correct positions
        // and gives us the actual itinerary from JFK to the end.
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};