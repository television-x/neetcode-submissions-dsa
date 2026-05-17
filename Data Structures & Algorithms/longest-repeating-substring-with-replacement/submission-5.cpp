class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int c=0;
        int mc=0;
        unordered_map<char,int> count;
        int r=0;
        while(r<s.size()){
            count[s[r]]++;
            c = max(c, count[s[r]]);
            if((r-l+1)-c<=k){
                mc = max(mc, r-l+1);
            }else{
                count[s[l]]--;
                l++;
            }
            r++;
        }
        return mc;
    }
};