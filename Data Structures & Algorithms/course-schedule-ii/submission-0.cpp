class Solution {
public:

    vector<vector<int>> adj;
    vector<int> in_degree;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        adj.resize(numCourses);
        in_degree.resize(numCourses);

        for (auto & edge: prerequisites) {
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
            in_degree[v] += 1;
        }

        queue<int> q;

        int count = 0;

        vector<int> result;

        for (int i = 0; i < numCourses; ++i) {
            if (in_degree[i] == 0){
                q.push(i);
                result.push_back(i);
                count += 1;
            }
        }

        while(!q.empty()) {
            int s = q.front();
            q.pop();

            for (int x : adj[s]) {
                in_degree[x]--;
                if (in_degree[x] == 0){
                    q.push(x);
                    count += 1;
                    result.push_back(x);
                }
            }
        }

        if (count == numCourses)
            return result;
        else
            return {};

    }
};
