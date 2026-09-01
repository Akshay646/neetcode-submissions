using P = pair<int, int>;
using MinHeap = priority_queue<P, vector<P>, greater<P>>;

class Solution {
public:

    vector<int> GetDistancesByDijkstra(
        vector<vector<pair<int, int>>>& graph,
        MinHeap& pq,
        int n,
        int k
    ) {

        // stores the shortest distances
        // initially we don't know any distance, so keep everything as INF
        vector<int> distances(n + 1, INT_MAX);

        // distance from source node to itself is 0
        distances[k] = 0;

        // pq stores {distance, node}
        pq.push({0, k});

        while (!pq.empty()) {

            // get the node with the smallest current distance
            auto [d, pNode] = pq.top();
            pq.pop();

            // this is an old entry, we already found a smaller distance
            if (distances[pNode] < d) {
                continue;
            }

            // visit all neighbours of current node
            for (auto nbr : graph[pNode]) {

                // get neighbour node and edge weight
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                // distance to neighbour if we go through current node
                int newDist = d + nbrDist;

                // if this route is cheaper, update the distance
                if (newDist < distances[nbrNode]) {

                    distances[nbrNode] = newDist;

                    // push the new {distance, node}
                    pq.push({newDist, nbrNode});
                }
            }
        }

        return distances;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // nodes are 1 to n, so we need n + 1 positions
        vector<vector<pair<int, int>>> graph(n + 1);

        // build graph
        // graph[u] = {v, weight}
        for (auto time : times) {

            int ui = time[0];
            int vi = time[1];
            int wi = time[2];

            graph[ui].push_back({vi, wi});
        }

        // stores {distance, node}
        // smallest distance always stays on top
        MinHeap pq;

        vector<int> distances =
            GetDistancesByDijkstra(graph, pq, n, k);

        int nwDTime = 0;

        // check nodes 1 to n
        for (int node = 1; node <= n; node++) {

            // node cannot be reached
            if (distances[node] == INT_MAX) {
                return -1;
            }

            // we need the maximum time, not the sum
            // because we already have the minimum distance from source to every node
            // all nodes receive the signal at the same time
            // so the maximum distance is the time when the last node receives the signal
            nwDTime = max(nwDTime, distances[node]);
        }

        return nwDTime;
    }
};