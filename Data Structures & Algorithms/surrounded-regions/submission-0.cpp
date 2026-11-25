class Solution {
public:
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1},{-1,0}};

    void solve(vector<vector<char>>& matrix) {
        queue<pair<int,int>> q;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 'O'){
                q.emplace(i,0);
                matrix[i][0] = '#';
            }
            if (matrix[i][n-1] == 'O'){
                q.emplace(i,n-1);
                matrix[i][n-1] = '#';
            }
        }

        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 'O'){
                q.emplace(0,j);
                matrix[0][j] = '#';
            }
            
            if (matrix[m-1][j] == 'O'){
                q.emplace(m-1,j);
                matrix[m-1][j] = '#';
            }
        }



        while(!q.empty()){
            auto s = q.front(); q.pop();
            int i = s.first;
            int j = s.second;

            for (auto &dir : directions) {
                int newi = i + dir.first;
                int newj = j + dir.second;

                if (newi < 0 || newj < 0 || newi >= m || newj >= n)
                    continue;
                
                if (matrix[newi][newj] == 'O'){
                    q.emplace(newi,newj);
                    matrix[newi][newj] = '#';
                }
            }
        }

        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n ; ++j) {
                if (matrix[i][j] == '#')
                    matrix[i][j] = 'O';
                else
                    matrix[i][j] = 'X';
            }
        }
    }
};
