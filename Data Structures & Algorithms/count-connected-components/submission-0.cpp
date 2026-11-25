class Solution {
public:
    vector<vector<int>> adj;

    vector<bool> visited;

    void dfs(int source) {
        visited[source] = true;
        for (int &x: adj[source]){
            if (!visited[x])
                dfs(x);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        adj.resize(n);
        visited.resize(n, false);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i])
            {
                dfs(i);
                count += 1;
            }
        }

        return count;
    }
};
