class Solution {
public:
    vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<bool>> visited;
    priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq; 
    int swimInWater(vector<vector<int>>& grid) {
        pq.push({grid[0][0], {0,0}}); 

        int answer = INT_MIN;

        int m = grid.size();
        int n = grid[0].size();

        visited.resize(m, vector<bool>(n, false));

        while(!pq.empty()) {
            auto [wt, pos] = pq.top();
            pq.pop();
            auto [i,j] = pos;

            if (visited[i][j])
                continue;
            
            visited[i][j] = true;

            answer = max(answer, wt);

            if (i == m-1 && j == n-1)
                return answer;

            for (auto &dir : directions) {
                int newi = i + dir.first;
                int newj = j + dir.second;

                if (newi < 0 || newj < 0 || newi >= m|| newj >= n)
                    continue;
                
                else{
                    pq.push({grid[newi][newj], {newi, newj}});
                }
            }
        }

        return answer;
    }
};
