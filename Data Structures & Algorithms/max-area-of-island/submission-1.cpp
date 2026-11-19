class Solution {
public:
    using pii = pair<int,int>;
    int n, m;
    vector<pii> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (grid[i][j] == 0)
            return 0;
        
        if (grid[i][j] == 1)
            grid[i][j] = 0;

        int count = 1;

        for (auto &dir : directions) {
            int newi = i + dir.first;
            int newj = j + dir.second;

            if (newi < 0 || newj < 0 || newi >= n || newj >= m || grid[newi][newj] == 0) {
                continue;
            }

            count += dfs(newi, newj, grid);
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1){
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }

        return ans;
    }
};


/*

0 - water
1 - land



*/