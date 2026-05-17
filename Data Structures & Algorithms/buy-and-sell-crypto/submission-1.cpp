class Solution {
public:
    int maxProfit(vector<int>& p) {
        if (p.empty()) return 0;

        int l = 0; 
        int r = 0; 
        int profit = 0;

        while (r < p.size()) {
            if (p[r] < p[l]) {
                l = r;
            } else {
                profit = max(profit, p[r] - p[l]);
            }
            r++; 
        }
        
        return profit;
    }
};