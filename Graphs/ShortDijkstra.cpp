class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges,
                             int src, int dest) {

        // 1. Build adjacency list
        vector<vector<pair<int, int>>> adj(V + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // 2. Dijkstra from destination
        const int INF = 1e9;

        vector<int> dist(V + 1, INF);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[dest] = 0;
        pq.push({0, dest});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto &[next, weight] : adj[node]) {

                if (d + weight < dist[next]) {

                    dist[next] = d + weight;

                    pq.push({dist[next], next});
                }
            }
        }

        // 3. No path exists
        if (dist[src] == INF)
            return {-1};

        // 4. Construct lexicographically smallest path
        vector<int> path;

        int node = src;
        path.push_back(node);

        while (node != dest) {

            int bestNode = INT_MAX;

            for (auto &[next, weight] : adj[node]) {

                // Is this edge part of a shortest path?
                if (weight + dist[next] == dist[node]) {

                    bestNode = min(bestNode, next);
                }
            }

            // Should never happen if dest is reachable
            if (bestNode == INT_MAX)
                return {-1};

            node = bestNode;
            path.push_back(node);
        }

        return path;
    }
};