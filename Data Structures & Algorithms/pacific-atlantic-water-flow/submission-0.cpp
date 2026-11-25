class Solution {
public:
    int m, n;
    vector<vector<bool>> atlantic, pacific;
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1},{-1,0}};

    
    vector<vector<bool>> visited;
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> & visited){
        if (visited[i][j] == true)
            return;
        
        visited[i][j] = true;

        for (auto dir : directions) {
            int newi = i + dir.first;
            int newj = j + dir.second;

            if (newi < 0 || newj < 0 || newi>= m || newj >= n || grid[i][j] > grid[newi][newj])
                continue;
            
            dfs(newi, newj, grid, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        atlantic.resize(m, vector<bool>(n, 0));
        pacific.resize(m, vector<bool>(n, 0));
        visited.resize(m, vector<bool>(n, 0));

        vector<vector<int>> result;

        // for (int i = 0; i < m ; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (i == 0 && j < n){
        //             dfs(i, j, grid, pacific);
        //         }else if (j < 1){
        //             dfs(i,j, grid, pacific);
        //         }
        //         if (i < m-1 && j > n - 2) {
        //             dfs(i, j, grid, atlantic);
        //         }else if (i == m-1){
        //             dfs(i, j, grid, atlantic);
        //         }

        //     }
        // }

        for (int i = 0; i < m; ++i) {
            dfs(i, 0, grid, pacific);       // left edge
            dfs(i, n - 1, grid, atlantic);  // right edge
        }
        for (int j = 0; j < n; ++j) {
            dfs(0, j, grid, pacific);       // top edge
            dfs(m - 1, j, grid, atlantic);  // bottom edge
        }


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (atlantic[i][j] && pacific[i][j])
                    result.push_back({i,j});
            }
        }

        return result;

    }
};
