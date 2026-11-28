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

        vector<int> d(n, INT_MAX);
        d[src] = 0;                          

        for (int i = 0; i <= k; ++i) {       
            vector<int> temp = d;
            for (auto &edge : flights) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if (d[u] != INT_MAX && d[u] + wt < temp[v]) {   
                    temp[v] = d[u] + wt;
                }
            }
            d = temp;
        }

        return d[dst] == INT_MAX ? -1 : d[dst];   
    }
};