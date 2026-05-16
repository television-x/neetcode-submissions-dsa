class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto num : nums)
            map[num]++;
        vector<pair<int, int>> result;
        for (const auto& p : map) {
            result.push_back({p.second, p.first});
        }
        sort(result.rbegin(), result.rend());
        vector<int> kfreq;
        for (int i = 0; i < k; i++) {
            kfreq.push_back(result[i].second);
        }
        return kfreq;
    }
};