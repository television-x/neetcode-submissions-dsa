class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      unordered_map<char, char> check;
      check[')']='(';
      check['}']='{';
      check[']']='[';

      for (int i=0; i<s.size(); i++){
        if (check.find(s[i]) == check.end()){
            st.push(s[i]);
        }
        else{
            if (st.empty() || st.top() != check[s[i]])  return false;
            st.pop();
        }
      }
      if (st.empty())   return true;
      else  return false;
    }
};
