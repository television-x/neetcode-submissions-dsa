class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> result;
        for (string s : strs){
            string key = string(26,0);
            for (char c: s){
                key[c-'a']++;
            }
            groups[key].push_back(s);
        }
        for (const auto it: groups){
            result.push_back(it.second);
        }
        return result;
    }
};
