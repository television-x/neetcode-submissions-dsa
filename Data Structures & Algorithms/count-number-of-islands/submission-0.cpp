class Solution {
public:
    int n, m;
    using pii = pair<int,int>;
    vector<pii> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<char>>& grid){
        if (grid[i][j] == '0')
            return;
        
        if (grid[i][j] == '1')
            grid[i][j] = '0';

        for (auto &dir : directions) {
            int newi = i + dir.first;
            int newj = j + dir.second;

            if (newi < 0 || newj < 0 || newi >= n || newj >= m || grid[newi][newj] == '0')
                continue;
            
            dfs(newi, newj, grid);

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1'){
                    dfs(i, j, grid);
                    count += 1;
                }
            }
        }
        return count;
    }
};

/*
[0 1 1 1 0]
[0 1 0 1 0]
[1 1 0 0 0]
[0 0 0 0 0]


[1 1 0 0 1]
[1 1 0 0 1]
[0 0 1 0 0]
[0 0 0 1 1]

1 ->land 
0 = water

return the number of island

island surrounded by water is land




*/
