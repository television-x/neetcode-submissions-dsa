class Solution {
public:
    vector<vector<bool>> visited;
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int m, n;
    vector<int> result;

    void dfs(int i, int j, vector<vector<int>>&matrix, int disha) {
        if (visited[i][j])
            return;
        
        visited[i][j] = true;
        result.push_back(matrix[i][j]);

        int newi = i + directions[disha].first;
        int newj = j + directions[disha].second;

        if (newi >= 0 && newj >= 0 && newi < m && newj < n && !visited[newi][newj])
            dfs(newi, newj, matrix, disha);
        
        disha = (disha + 1)%4;

        newi = i + directions[disha].first;
        newj = j + directions[disha].second;

        if (newi >= 0 && newj >= 0 && newi < m && newj < n && !visited[newi][newj])
            dfs(newi, newj, matrix, disha);
            
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        visited.resize(m, vector<bool>(n, false));
        dfs(0, 0, matrix, 0);

        return result;
    }

};
