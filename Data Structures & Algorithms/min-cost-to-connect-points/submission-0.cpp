class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<bool> mst;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        adj.resize(n);
        mst.resize(n, false);

        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }    

        set<pair<int,int>> q;
        q.insert({0,0}); // wt, to

        int sum = 0;

        while(!q.empty()) {

            auto [wt, s] = *q.begin();
            q.erase(q.begin());

            if (mst[s])
                continue;
            
            mst[s] = true;
            sum += wt;

            for (auto &x : adj[s]) {
                int to = x.first;
                int len = x.second;

                if (mst[to])
                    continue;
                
                q.emplace(len, to);
            }

        }

        return sum;
    }
};
