class Solution {
public:
    unordered_map<char, vector<char>> adj;
    vector<int> indegree;

    string foreignDictionary(vector<string>& words) {
        // we need to build the adj list
        // and find which one is smaller 
        // do topological sort on this and return the ans;

        indegree.resize(26, 0);
        unordered_map<char,int> mapping;


        int n = words.size();

        for (string &word : words) {
            for (char &ch : word) {
                mapping[ch] += 1;
            }
        }

        for (int i = 0; i < n-1 ; ++i) {
            const string word1 = words[i];
            const string word2 = words[i+1];

            int len = min(word1.length(), word2.length());
            bool found = false;
            for (int pos = 0; pos < len; pos++) {
                if (word1[pos] == word2[pos])
                    continue;
                
                adj[word1[pos]].push_back(word2[pos]);
                indegree[word2[pos]-'a'] += 1;
                found = true;
                break;
            }

            if (!found && word1.length() > word2.length())
                return "";
        }

        queue<char> q;
        string result = "";

        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && mapping.count(i+'a')){
                q.push(i+'a');
                result += (i+'a');
            }
        }

        while(!q.empty()) {
            auto s = q.front();
            q.pop();
            
            for (auto &x : adj[s]) {
                
                indegree[x-'a'] -= 1;
                if (indegree[x-'a'] == 0){
                    q.push(x);
                    result += x;
                }
            }
        }

        int unique_count = mapping.size();

        return (unique_count == result.length()) ? result : "";


    }
};
/*
order of letters is unknown

words list given and they are sorted is ascending order according to their language

goal : we need to build the graph for alphabets like which is smaller than the previous one

the relationship defined is : example (x is smaller than i) then x -> i and so on

and if there is cycle in the graph then we return "";
*/
