class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0; int maxCount = 0;
        unordered_map<char, bool> map;
        int l = 0;
        int r = 0;
        
        while (l != s.size() && r != s.size()) {
            if (map.find(s[r]) == map.end()) {
                map[s[r]] = true;
                count++;
                r++;
                maxCount = max(maxCount, count); // Track max continuously
            } else {
                // Shrink window from the left ONLY until the duplicate is gone
                while (s[l] != s[r]) {
                    map.erase(s[l]); // Completely remove the character
                    count--;
                    l++;
                }
                // Erase the old duplicate itself, then move l past it
                map.erase(s[l]);
                count--;
                l++;
            }
        }
        return maxCount;
    }
};