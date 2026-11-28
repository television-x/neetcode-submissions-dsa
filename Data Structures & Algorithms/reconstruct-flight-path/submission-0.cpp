class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string> path;
    stack<string> _stack;

    void dfs(string source) {
        _stack.push(source);
        while(!_stack.empty()) {
            auto _top = _stack.top();
            if (adj[_top].size() == 0) {
                _stack.pop();
                path.push_back(_top);
            }else{
                auto it = adj[_top].begin();
                auto next_source = *it;
                adj[_top].erase(it);
                dfs(next_source);
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto&edge: tickets) {
            const string u = edge[0];
            const string v = edge[1];

            adj[u].insert(v);
        }

        dfs("JFK"); 

        reverse(path.begin(), path.end());

        return path;
    }

};
