class Solution {
public:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> visited;

    bool function(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < (int)a.size(); ++i)
            if (a[i] != b[i] && ++diff > 1) 
                return false;
        return diff == 1;
}

    int ladderLength(string beginword, string endword, vector<string>& wordlist) {

        if (find(wordlist.begin(), wordlist.end(), beginword) == wordlist.end())
            wordlist.push_back(beginword);
        
        for (string &x : wordlist) {
            for (string &y : wordlist){
                if (x == y)
                    continue;
                if (function(x, y)){
                    adj[x].push_back(y);
                    adj[y].push_back(x);
                }
            }
        }

        queue<string> q;
        q.push(beginword);
        visited[beginword] = true;


        int level = 1;

        while(!q.empty()) {
            int _n = q.size();
            
            while(_n--){
                string s = q.front();
                q.pop();

                for (string &x : adj[s]){
                    
                    if (x == endword)
                        return level+1;

                    if (!visited[x]){
                        q.push(x);
                        visited[x] = true;
                    }

                }
            }
            level += 1;
        }

        if (visited.count(endword))
            return level;
         
        else
            return 0;


    }
};
