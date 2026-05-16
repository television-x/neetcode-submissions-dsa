class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> freq;
        vector<int> result;
        for (int i=0; i<nums.size();i++){
            freq[nums[i]]++;
        }
        while(k!=0){
            int maxcount=0;
            int maxelement=0;
            for (const auto it : freq){
                if (it.second>maxcount){
                    maxcount=it.second;
                    maxelement = it.first;
                }
            }
            result.push_back(maxelement);
            k--;
            freq.erase(maxelement);
        }
        return result;
    }
};
