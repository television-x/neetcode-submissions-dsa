class Solution {
public:
    int maxProfit(vector<int>& p) {
        //case 1
        bool desc=false;
        for (int i=1;i<p.size();i++){
            if (p[i-1]<p[i]){
                desc=false;
                break;
            }
        }
        if (desc)   return 0;
        
        //case 2
        bool asc=false;
        for (int i=0;i<p.size()-1;i++){
            if (p[i]>p[i+1]){
                asc=false;
                break;
            }
        }
        if(asc) return p[p.size()-1]-p[0];


        //case 3
        int l=0;
        int r=0;
        int profit=0;
        while(r<p.size()){
            if (p[r]-p[l]==0){
                profit = max(profit, p[r]-p[l]);
                r++;
            }
            else if(p[r]-p[l]<0){
                l=r;
            }else{
                profit = max(profit, p[r]-p[l]);
                r++;
            }
        }
        return profit;
    }
};
