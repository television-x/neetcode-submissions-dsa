class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j = heights.size()-1;
        int hmax=0;
        while (i<j){
            int result = (j-i)*min(heights[i],heights[j]);
            hmax = max(hmax,result);
            if (heights[i]>heights[j]){
                j--;
            }else{
                i++;
            }
        }
        return hmax;
    }
};
