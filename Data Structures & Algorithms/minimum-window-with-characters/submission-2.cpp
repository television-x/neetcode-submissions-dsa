class Solution {
public:
    string minWindow(string s, string t) {
        if (t=="")   return "";
        if (s.size()<t.size())  return "";

        unordered_map<char,int> countT;
        unordered_map<char, int> window;

        for (int i=0;i<t.size(); i++){
            countT[t[i]]++;
        }

        int have=0, need = countT.size();
        int len=INT_MAX;
        int index=-1;

        int i=0,j=0;
        
        while(j<s.size()){
            window[s[j]]++;
            if (countT.find(s[j]) != countT.end()){
                if (window[s[j]] == countT[s[j]])   have++;
            }
            while (have == need){
                if (j-i+1 < len){
                    index = i;
                    len = j-i+1;
                }
                window[s[i]]--;
                if (countT.find(s[i]) != countT.end()){
                    if (window[s[i]] < countT[s[i]])    have--;
                }
                i++;
            }
            j++;
        }
        if (index==-1)   return "";
        else    return s.substr(index, len);

    }
};
