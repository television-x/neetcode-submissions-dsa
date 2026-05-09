class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int hmax=0;
        while(i<j){
            int result=(j-i)* min(height[j],height[i]);
            hmax = max(hmax,result);
            if (height[i]>height[j])    j--;
            else    i++;
        }
        return hmax;
    }
};