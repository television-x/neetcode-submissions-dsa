class Solution {
public:
    int m, n;
    
    const int INF = 2147483647;

    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1},{-1,0}};
    using pii = pair<int,int>;


    void islandsAndTreasure(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0){
                    q.emplace(i,j);
                    visited[i][j] = true;
                }
            }
        }


        int level = 1;
        while(!q.empty()) {
            int N = q.size();
            while(N--) {
                auto s = q.front();
                q.pop();

                int i = s.first, j = s.second;

                for (auto &dir : directions) {
                    int newi = i + dir.first;
                    int newj = j + dir.second;

                    if (newi < 0 || newj < 0 || newi >= m || newj >= n || grid[newi][newj] == -1)
                        continue;

                    if (level < grid[newi][newj]) {
                        grid[newi][newj] = level;
                    }

                    if (visited[newi][newj])
                        continue;

                    visited[newi][newj] = true;

                    q.emplace(newi, newj);
                }
            }
            level += 1;
        }
        
    }
};
