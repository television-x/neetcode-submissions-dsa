class Solution {
public:
    const int inf = 1e9+1;
    using pii = pair<int,int>;
    vector<vector<pii>> adj;
    set<pii> q;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        adj.resize(n);

        for (auto&edge : times) {
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];
            adj[--from].push_back({--to, wt});
        }

        vector<int> distance(n, inf);

        distance[--k] = 0;

        q.insert({0,k}); // wt, src.;

        while(!q.empty()) {
            auto [d,s] = *q.begin();
            q.erase(q.begin());

            if (d > distance[s])
                continue;

            for (auto &x : adj[s]) {
                int to = x.first;
                int len = x.second;

                if (distance[s] + len < distance[to]) {
                    q.erase({distance[to], to});
                    distance[to] = distance[s] + len;
                    q.insert({distance[to], to});
                }
            }
        }

        int _max = *max_element(distance.begin(), distance.end());
        
        if (_max == inf)
            return -1;
        else
            return _max;
    }
};
