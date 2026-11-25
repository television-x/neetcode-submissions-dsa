class Solution {
public:
    vector<vector<int>> adj;

    vector<bool> in_recursion;

    vector<bool> visited;

    bool dfs_cycle(int source) {
        in_recursion[source] = true;
        visited[source] = true;
        for (int &x : adj[source]){
            if (in_recursion[x])
                return true;
            
            if (!visited[x] && dfs_cycle(x))
                return true;
        }
        in_recursion[source] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);

        in_recursion.assign(numCourses, false);

        visited.resize(numCourses, false);

        for (auto &edge: prerequisites) {
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
        }

        bool result;

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]){
                result = dfs_cycle(i);
                if (result)
                    return false;
            }
        }

        return !result;
    }
};
