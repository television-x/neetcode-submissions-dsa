class Solution {
public:
    bool isPalindrome(string s) {
       string s1="" ;
    //    string so = s.tolower();
       int len = s.size();
       for(int i=0; i<len; i++){
        if (!isalnum(s[i])){
            continue;
        }
        else{
            s1+=(char)tolower(s[i]);
        }
       }
       string s2(s1.rbegin(), s1.rend());

       if (s1==s2)  return true;

       return false;

    }
};
