class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxCount=0;
        
        for (int i=0; i<s.size(); i++){
            unordered_map<char,int> map;
            int count=0;
            for (int j=i; j<s.size(); j++){
                map[s[j]]++;
                count = max(count, map[s[j]]);
                if ((j-i+1)-count <= k){
                    maxCount = max(maxCount, j-i+1);
                }
            }
            
        }
        return maxCount;
    }
};
