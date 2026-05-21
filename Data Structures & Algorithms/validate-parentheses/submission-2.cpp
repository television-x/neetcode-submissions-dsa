class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> temp_stack;
        std::map<char, char> matching_brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                temp_stack.push_back(c); 
            } else if (c == ')' || c == ']' || c == '}') {
                if (temp_stack.empty() || temp_stack.back() != matching_brackets[c]) {
                    return false; 
                }
                temp_stack.pop_back(); 
            }
        }

        return temp_stack.empty(); 
    }
};