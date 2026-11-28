class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> hops(n, INT_MAX);
        vector<vector<int>> adj(n);

        for (auto &edge : flights) {
            adj[edge[0]].push_back(edge[1]);
        }

        // queue<int> q;
        // q.push(src);
        // hops[src] = 0;

        // while (!q.empty()) {
        //     int v = q.front();
        //     q.pop();
        //     for (int u : adj[v]) {
        //         if (hops[u] == INT_MAX) {
        //             hops[u] = hops[v] + 1;
        //             q.push(u);
        //         }
        //     }
        // }

        // if (hops[dst] > k + 1) return -1;  
        const int inf = INT_MAX/2;
        vector<int>distance(n, inf);

        distance[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> _distance = distance;
            for (auto &edges : flights) {
                int u = edges[0];
                int v = edges[1];
                int wt = edges[2];

                if (distance[u] != inf && distance[u] + wt < _distance[v])
                {
                    _distance[v] = wt + distance[u];
                }
            }
            distance = _distance;
        }

        return (distance[dst] == inf) ? -1 : distance[dst];
        

    }
};