class Solution {
public:
    unordered_map<int,bool> row;
    unordered_map<int, bool> col;
    int m, n;
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<bool>> visited;

    void dfs(int i, int j, vector<vector<int>>&matrix) {
        if (visited[i][j])
            return;

        visited[i][j] = true;

        if (matrix[i][j] != 0){
            if (row.count(i) || col.count(j)){
                matrix[i][j] = 0;
            }
            
        }

        for (auto &dir : directions) {
            int newi = i + dir.first;
            int newj = j + dir.second;

            if (newi < 0 || newj < 0 || newi >= m || newj >= n)
                continue;
            
            dfs(newi, newj, matrix);
        }
        
        

    }
    void setZeroes(vector<vector<int>>& matrix) {
        m =matrix.size();
        n = matrix[0].size();

        visited.resize(m, vector<bool>(n, false));

        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        dfs(0,0, matrix);
    }
};
