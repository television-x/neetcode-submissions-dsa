class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> maps;
        unordered_map<char,int> mapt;

        if(s.size() != t.size())    return false;

        for (int i=0; i<s.size();i++){
            maps[s[i]]++;
        }
        for (int i=0; i<t.size();i++){
            mapt[t[i]]++;
        }

        if (maps == mapt){
            return true;
        }

        return false;

    }
};
