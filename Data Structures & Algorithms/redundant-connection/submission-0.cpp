class Solution {
private: 
    // vector<vector<int>> adj;
    vector<int> parent;
    vector<int> rank;

public:

    int find (int i) {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y){
        int _x = find(x);
        int _y = find(y);

        if (rank[_x] > rank[_y]) {
            parent[_y] = _x;
        }else if (rank[_y] > rank[_x]) {
            parent[_x] = _y;
        }else{
            parent[_x] = _y;
            rank[_y] += 1;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        parent.assign(n+1, 0);
        rank.assign(n+1, 0);

        vector<int> result;

        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }

        for (auto & edge : edges ) {
            int u = edge[0];
            int v = edge[1];

            if (find(u) == find(v)){
                result.push_back(u);
                result.push_back(v);
                break;
            }else{
                Union(u,v);
            }

        }
        return result;
    }
};
