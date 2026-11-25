class Solution {
public:
    vector<vector<int>> adj;

    vector<bool> visited;

    void dfs(int source){
        visited[source] = true;

        for (int &x : adj[source]) {
            if (!visited[x])
                dfs(x);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        if ((int)edges.size() != n - 1)
            return false;

        adj.resize(n);

        visited.resize(n, false);

        for (auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0);

        for (int i = 0; i < n; ++i ) {
            if (!visited[i])
                return false;

        }

        return true;
    }
};
