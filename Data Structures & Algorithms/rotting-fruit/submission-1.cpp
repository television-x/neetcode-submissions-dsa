class Solution {
public:
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1},{-1,0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0; // need to check if there are no fresh items

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2){
                    q.emplace(i,j);
                    grid[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    ++fresh;
            }
        }

        if (fresh == 0)
            return 0;

        int time = 0;
        while(!q.empty()) {
            int _n = q.size();

            while(_n--) {
                auto s = q.front();
                q.pop();

                int i = s.first;
                int j = s.second;

                for (auto &dir : directions) {
                    int newi = dir.first + i;
                    int newj = dir.second + j;

                    if (newi < 0 || newj < 0 || newi >= m || newj >= n || grid[newi][newj] == 0)
                        continue;
                    
                    grid[newi][newj] = 0;
                    fresh--;
                    q.emplace(newi, newj);
                }
            }
            time += 1;
        }


        if (fresh == 0)
            return time-1;
        else
            return -1;
    }
};
